#include "Format.h"
#include "Exceptions.h"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Image.hpp>
#include <cstddef>
#include <cstdint>
#include <fmt/core.h>
#include <format>
#include <fstream>
#include <bitset>
#include <stdexcept>

template <std::size_t S>
void Format::write(const std::bitset<S>& bitset, const int& offset){
  for(int i=0; i<bitset.size(); i++, pxar+=offset){
    if(!alpha){ 
      if(alphaCounter%4==0){
        alphaCounter= 1;
        pxar++;
      }
      alphaCounter+=offset;
    }

    if(bitset[i]==(*pxar&true)){
      continue;
     }

    if(bitset[i]&true)
      ++*pxar;
    else
      --*pxar;
  }
}

template <size_t S>
void Format::read(std::bitset<S>& bitset, const int& offset){
  for(int i=0; i<S; i++, pxar+=offset){
    if(!alpha) {
      if(alphaCounter%4==0){
        alphaCounter=1;
        pxar++;
      }
      alphaCounter+=offset;
    }
    bitset.set(i, *pxar&true);
  }
}

bool Format::alphaChannelExists(){
  auto arr = pxar+3;

  for(int i=4; i<size; i+=4, arr+=4)
    if(*arr!=0xFF) return true;
  return false;
}

int Format::calculateOffset(){
  auto uLength = (alpha ? size/8: size/8*3/4)-32;
  return uLength/(message.size()+32);
}

bool inString(const std::string& str, const std::string& entry){
  return str.find(entry)!=str.npos;
}

template <size_t N>
bool inString(const std::string& str, const std::string (&entries)[N]){
  bool result=false;
  for(const auto& entry: entries) result=result or inString(str, entry); 
  return result;
}

Formats Format::getFormat(){
    unsigned char* firstBytes = new unsigned char[16];
    std::ifstream istream = std::ifstream(ifile);
    istream.read(reinterpret_cast<char*>(firstBytes), 16);
    istream.seekg(0);
    

    auto str = std::string(reinterpret_cast<char*>(firstBytes));

    std::string ppm[]={"P5", "P6"};
    if(inString(str, ppm)){
       return Formats::PPM;
    }
    if(inString(str, "PNG")){
      return Formats::PNG;
    }
    std::string bmp[]={"BM", "BA", "CI", "CP", "IC", "PT"};
    if(inString(str, bmp)){
      return Formats::BMP;
    }
    if(inString(str, "8BPS")){
      return Formats::PSD;
    }
    std::string hdr[] = {"#?RADIANCE", "#?RGBE"};
    if(inString(str, hdr)){
      return Formats::HDR;
    }
    if(firstBytes[0]==0xFF and firstBytes[1]==0xD8){
      return Formats::JPG;
    }
    if(inString(str, "GIF")){
      return Formats::GIF;
    }
    
    throw UnsupportedFormat();
}

std::string getSize(sf::Image image){
  auto size = image.getSize();
  return fmt::format("{}x{}", size.x, size.y);
}

void Format::printInfo(){
    fmt::println("Format:\t\t\t{}", format); 
    fmt::println("Size:\t\t\t{}", getSize(image));
    auto file = std::filesystem::path(ifile);
    auto time = std::filesystem::last_write_time(file);

    fmt::println("File Size:\t\t{:.1f} MB", static_cast<float>(std::filesystem::file_size(file))/1024/1024);
    fmt::println("Last write time:\t{}", std::format("{}", time).substr(0, 19));
}



void printCheck(const int& length, const int& size, const bool& result){
    fmt::println("Message size:\t\t{}", size);
    fmt::println("Possible length of\ntext inside image:\t{}", length);
    fmt::println("\n{}", result ? "Message fits in image" : "Image is too small" );

}

void Format::operate() {
    switch (op){
        case Operation::ENCRYPT:
            return encrypt();
        case Operation::DECRYPT:
            return decrypt();
        case Operation::INFO:
            return printInfo();
        case Operation::CHECK:
            check();
    }

};

void Format::encrypt(){
  if(!check(true)){
      throw std::logic_error("image is too small to store the message");
  } 
  auto px = pxar;

  auto of = std::bitset<32>(offset);
  write(of);

  auto length = std::bitset<32>(message.size());
  write(length, offset);

  for(const char& c: message){
      auto bitset = std::bitset<8>(c);
      write(bitset, offset); 
  }

  auto result = sf::Image();

  result.create(image.getSize().x, image.getSize().y, px);      
  result.saveToFile(ofile);
}

void Format::decrypt(){
  std::string message;
  std::bitset<32> of;
  std::bitset<32> length; 
  std::bitset<8> c;

  read(of);
  offset = of.to_ulong();

  if(offset*32L>size-32) 
    throw std::logic_error("offset is greater then image size\nfile "
                          "may not contain message or was corrupted/changed");  

  read(length, offset);
  auto l = length.to_ulong();

  if(1L*l*offset>size-32L*offset-32) throw std::logic_error("calculated length is greater then image size\nfile "
                                                                "may not contain message or was corrupted");

  for(int i=0; i<length.to_ulong(); i++){
    read(c, offset);
    message+=c.to_ullong();
  }

  if(ofile!=""){
    auto stream = std::ofstream(ofile);
    for(const char &c: message){
      stream<<c;
    }
    return;
  }
  fmt::println("{}", message);
}

bool Format::check(const bool& quiet){
  auto uLength = (alpha ? size/8: size/8*3/4)-64;
  bool result = message.size()<=uLength ? true: false; 

  if(!quiet)printCheck(uLength, message.size(), result);

  return result;
}
