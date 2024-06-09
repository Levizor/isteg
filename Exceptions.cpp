#include "Exceptions.h"

NoSuchFile::NoSuchFile(const char* file){ 
    message = fmt::format("{}: No such file or directory", file);
}

const char *NoSuchFile::what() const noexcept {
    return message.c_str();
}

InvalidOption::InvalidOption(const char *opt){ 
    message = fmt::format("invalid option: {}", opt);
}

const char *InvalidOption::what() const noexcept {
    return message.c_str();
}

const char *UnsupportedFormat::what() const noexcept {
    return "not supported format. Supported formats are:\n"
      "Input: PPM, PNG, JPG, BMP, PSD, HDR, TGA, GIF\n"
      "Output: BMP, PNG, TGA";
}

