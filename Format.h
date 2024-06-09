#pragma once
#include <SFML/Graphics/Image.hpp>
#include <algorithm>
#include <bitset>
#include <cstdint>
#include <fstream>
#include <string>
#include <fmt/core.h>
#include <SFML/Graphics.hpp>
#include "Args.h"
#include <filesystem>
#include <chrono>
#include <format>
#include <fmt/format.h>

enum class Formats {
    PPM, BMP, PNG, PSD, TGA, HDR, JPG, GIF
};

auto inline format_as(Formats f){
    switch(f){
      case Formats::PPM:
        return "PPM";
      case Formats::BMP:
        return "BMP";
      case Formats::PNG:
        return "PNG";
      case Formats::HDR:
        return "HDR";
      case Formats::PSD:
        return "PSD";
      case Formats::JPG:
        return "JPG";
      case Formats::TGA:
        return "TGA";
      case Formats::GIF:
        return "GIF";
      default:
        return "";
    }
}

class Format: public Args{
  public:
    Formats format;
    int alphaCounter=1;
    bool alpha=false;
    uint8_t* pxar;
    int size;
    sf::Image image;
    int offset;

    Format(const Args& args):Args(args), image(sf::Image()){
       format = getFormat();
       image.loadFromFile(ifile);
       auto c_pxar = image.getPixelsPtr();
       size = image.getSize().x*image.getSize().y*4;

       pxar = new uint8_t[size];
       std::copy(c_pxar, c_pxar+size, pxar);

       alpha = alphaChannelExists();
       offset = calculateOffset();
    }


    bool alphaChannelExists();

    Formats getFormat();
    
    void printInfo();

    void encrypt();

    void decrypt();

    bool check(const bool& quiet=false);

    void operate();

  private:

    int calculateOffset();
    
    template <size_t S>
    void write(const std::bitset<S>& bitset, const int& offset=1);

    template <size_t S>
    void read(std::bitset<S>& bitset, const int& offset=1);
};
