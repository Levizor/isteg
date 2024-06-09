#pragma once
#include <cstring>
#include <ostream>
#include <string>
#include <fstream>

enum class Operation {
    NOOP=-1, ENCRYPT, DECRYPT, INFO, CHECK, HELP
};

struct Args {
    Operation op=Operation::NOOP;
    std::string ifile;
    std::string ofile;
    std::string message;

    Args(){};

};

class ArgParser:public Args{
  public:
    const int &argc;
    const char **argv;

    ArgParser(const int &argc, const char *argv[]):Args(), argc(argc), argv(argv) {
    };

    void parse();

    void parseFile(int &i);

    void parseMessage(int& i);

    bool isSubArg(const int &i);
};
