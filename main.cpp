#include "Args.h"
#include "Exceptions.h"
#include "Format.h"
#include <fmt/core.h>

void printUsage() {
  fmt::println(
      "Usage: isteg [OPTION] [FILE] [TEXT or -f FILE] -o [OUTPUT FILE]");
}

auto printFlag(const std::string &option, const std::string &alias,
               const std::string &description) {
  fmt::println("  -{}, --{}\t\t{}", option, alias, description);
}

void printHelp() {
  printUsage();
  fmt::println("Tool for hiding text (or files) inside images.\n");
  printFlag("h", "help", "show this help message");
  printFlag("e", "encode",
            "encode text in image. Usage: isteg -e FILENAME STRING");
  printFlag(
      "f", "file",
      "specify file to hide in image. Usage: isteg -e FILENAME -f FILENAME");
  printFlag("d", "decode", "decode text from image");
  printFlag("i", "info", "show information about image");
  printFlag("c", "check", "check if it's possible to encode text in image");
  printFlag("o", "output", "specify file to output");

  fmt::println("\nCurrently supported formats: ");
  fmt::println("Input: PPM, PNG, JPG, BMP, PSD, HDR, TGA, GIF");
  fmt::println("Output: BMP, PNG, TGA");
  fmt::println("\nDefault output file format is PNG");
}

auto main(int argc, const char *argv[]) -> int {

  auto argp = ArgParser(argc, argv);

  try {
    argp.parse();
    if (argp.op == Operation::HELP) {
      printHelp();
      return 0;
    }

    Format(argp).operate();
    return 0;

  } catch (const InvalidOption &exception) {
    fmt::println(stderr, "isteg: {}", exception.what());
    fmt::println("Try 'isteg --help' for more information");
    return 1;
  } catch (const NoSuchFile &exception) {
    fmt::println(stderr, "isteg: {}", exception.what());
    fmt::println("Try 'isteg --help' for more information");
    return 1;
  } catch (const NoArgs &exception) {
    printUsage();
    return 1;
  } catch (const std::exception &exception) {
    fmt::println(stderr, "isteg: {}", exception.what());
    return 1;
  }
}
