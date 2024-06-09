#pragma once
#include <exception>
#include <stdexcept>
#include <fmt/format.h>


class NoSuchFile : public std::exception{
public:
    const char *filename;
    std::string message;

    NoSuchFile(const char *file);
    virtual const char *what() const noexcept override;

};

class IsDirectory: public NoSuchFile{
  public:
    IsDirectory(const char* dirname): NoSuchFile(dirname){
      message = fmt::format("{}: Is a directory", dirname);
    }
};

class ImageTooSmall: public std::logic_error{
  public:
    ImageTooSmall():std::logic_error("image is too small to store the message"){};
};

class InvalidOption : public std::exception{
    const char *opt;
    std::string message;
public:
    InvalidOption(const char *opt); 
    virtual const char *what() const noexcept override; 
    
};

class UnsupportedFormat : public std::exception {
public:
    virtual const char *what() const noexcept override;
};

class NoArgs : public std::exception {
};
