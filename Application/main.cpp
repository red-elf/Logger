#include <string>
#include <argparse/argparse.hpp>
#include "Logger.h"
#include "LogLevel.h"
#include "LoggerSimple.h"
#include "LoggerFactory.h"
#include "LoggerLibrary.h"
#include "BuildConfig.h"

int main(int argc, char *argv[]) {

    auto relog = "relog";
    auto version = std::to_string(VERSIONABLE_VERSION_PRIMARY) +
                   "." + std::to_string(VERSIONABLE_VERSION_SECONDARY) +
                   "." + std::to_string(VERSIONABLE_VERSION_PATCH);

    if (VERSIONABLE_SNAPSHOT) {

        version += "-SNAPSHOT";
    }

    argparse::ArgumentParser program(relog, version);

    program
            .add_argument("-l", "--level")
            .help("Log level: verbose (v), debug (d), info (i), warning (w), error (e)");

    program.add_argument("-t", "--tag")
            .help("The log tag");

    program.add_argument("-m", "--message")
            .help("The log message (required!)")
            .required();

    try {

        program.parse_args(argc, argv);
    }
    catch (const std::runtime_error &err) {

        std::cerr << err.what() << std::endl;
        std::cerr << program;
        std::exit(1);
    }

    return 0;
}
