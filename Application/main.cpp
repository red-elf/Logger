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
    auto version = std::to_string(VERSIONABLE_VERSION_PRIMARY)
            .append(".")
            .append(std::to_string(VERSIONABLE_VERSION_SECONDARY))
            .append(".")
            .append(std::to_string(VERSIONABLE_VERSION_PATCH));

    if (VERSIONABLE_SNAPSHOT) {

        version.append("-SNAPSHOT");
    }

    argparse::ArgumentParser program(relog, version);

    program
            .add_argument("-l", "--level")
            .default_value(std::string("v"))
            .help("Log level: verbose (v), debug (d), info (i), warning (w), error (e)");

    program.add_argument("-t", "--tag")
            .default_value(std::string(""))
            .help("The log tag");

    program.add_argument("-m", "--message")
            .help("The log message (required!)")
            .required();

    std::string description("Red Elf Logger");
    description.append(" (").append(relog).append(")");

    // TODO: Obtain the value via BuildConfig:
    std::string landingPage("https://github.com/red-elf/Logger");
    std::string epilog("Project homepage: ");
    epilog.append(landingPage);

    program.add_description(description);
    program.add_epilog(epilog);

    try {

        program.parse_args(argc, argv);
    }
    catch (const std::runtime_error &err) {

        std::cerr << err.what() << std::endl;
        std::cerr << program;
        std::exit(1);
    }

    try {

        auto tag = program.get<std::string>("tag");
        auto level = program.get<std::string>("level");
        auto message = program.get<std::string>("message");

        LoggerSimple logger;
        logger.log(LogLevel::verbose, message);

    } catch (std::logic_error &e) {

        std::cout << "No message provided" << std::endl;
    }

    return 0;
}
