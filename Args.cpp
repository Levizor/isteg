#include "Args.h"
#include "Exceptions.h"
#include <algorithm>
#include <cstring>
#include <filesystem>
#include <fmt/core.h>
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string>

std::string addSufix(std::string s) {
  return s.insert(s.find_last_of('.'), "_steg");
}

std::string changeExtension(std::string s) {
  auto pos = s.find_last_of(".");
  auto substr = s.substr(0, pos);
  return substr + ".png";
}

bool ArgParser::isSubArg(const int &i) {
  return i < argc and argv[i][0] != '-';
}

bool equal(const char *arg, const char *flag, const char *alias) {
  return std::strcmp(arg, flag) == 0 or std::strcmp(arg, alias) == 0;
}

void ArgParser::parseFile(int &i) {
  if (!isSubArg(i)) {
    throw std::logic_error(std::string(argv[i - 1]) + ": missing file operand");
  }
  ifile = argv[i];

  // checking existence of the file
  auto path = std::filesystem::path(ifile);
  if (std::filesystem::is_directory(path)) {
    throw IsDirectory(path.c_str());
  }

  auto perm = std::filesystem::status(path).permissions();
  using std::filesystem::perms;
  if ((perm & perms::owner_read) == perms::none) {
    throw std::logic_error("No permission to read specified file.");
  }
  auto istream = std::ifstream(ifile);
  if (!istream.is_open()) {
    throw NoSuchFile(ifile.c_str());
  }
}

void ArgParser::parseMessage(int &i) {
  if (!isSubArg(i)) {
    if (i < argc and equal(argv[i], "-f", "--file")) {
      i++;
      if (!isSubArg(i)) {
        throw std::logic_error(std::string(argv[i - 1]) +
                               ": missing file operand");
      }

      std::ifstream stream = std::ifstream(argv[i], std::ios::binary);
      if (!stream.is_open()) {
        throw NoSuchFile(argv[i]);
      }

      stream.seekg(0, std::ios::end);
      std::streamsize size = stream.tellg();
      stream.seekg(0, std::ios::beg);

      message = std::string(size, '\0');

      stream.read(&message[0], size);

    } else
      throw std::logic_error(std::string(argv[i - 1]) +
                             ": missing message operand");
  } else {
    message = std::string(argv[i]);
  }
}

void ArgParser::parse() {
  // retreiveng all the passed arguments
  if (argc < 2)
    throw NoArgs();
  for (auto i = 1; i < argc; i++) {

    if (argv[i][0] != '-') {
      throw InvalidOption(argv[i]);
    }

    if (equal(argv[i], "-h", "--help")) {
      op = Operation::HELP;
      return;
    } else if (equal(argv[i], "-e", "--encode")) {
      if (op != Operation::NOOP) {
        throw std::logic_error("More than one operation specified");
      }
      op = Operation::ENCRYPT;

      parseFile(++i);
      parseMessage(++i);
    } else if (equal(argv[i], "-d", "--decode")) {
      if (op != Operation::NOOP) {
        throw std::logic_error("More than one operation specified");
      }
      op = Operation::DECRYPT;

      parseFile(++i);
    } else if (equal(argv[i], "-i", "--info")) {
      if (op != Operation::NOOP) {
        throw std::logic_error("More than one operation specified");
      }
      op = Operation::INFO;
      parseFile(++i);
    } else if (equal(argv[i], "-c", "--check")) {
      if (op != Operation::NOOP) {
        throw std::logic_error("More than one operation specified");
      }
      op = Operation::CHECK;
      parseFile(++i);
      parseMessage(++i);
    } else if (equal(argv[i], "-o", "--output")) {
      if (!isSubArg(++i)) {
        throw std::logic_error(std::string(argv[i - 1]) +
                               ": missing file operand");
      }
      ofile = argv[i];
      if (op == Operation::DECRYPT)
        continue;

      auto last3 = ofile.substr(ofile.size() - 4, ofile.size() - 1);
      if (last3 != ".png" and last3 != ".bmp" and last3 != ".tga")
        throw UnsupportedFormat();

      auto path = std::filesystem::path(ofile);
      if (std::filesystem::is_directory(path)) {
        throw IsDirectory(path.c_str());
      }
      auto perm = std::filesystem::status(path).permissions();
      using std::filesystem::perms;
      if ((perm & perms::owner_write) == perms::none) {
        throw std::logic_error("No permission to write to specified file.");
      }
    } else {
      throw InvalidOption(argv[i]);
    }
  }

  // assigning output stream
  if (op == Operation::ENCRYPT) {

    if (ofile == "") {
      ofile = addSufix(ifile);
    }
    auto last3 = ofile.substr(ofile.size() - 4, ofile.size() - 1);
    if (last3 != ".png" and last3 != ".bmp" and last3 != ".tga")
      ofile = changeExtension(ofile);
  }
}
