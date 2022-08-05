#include <string>
#include <argparse/argparse.hpp>
#include "Logger.h"
#include "LogLevel.h"
#include "LoggerSimple.h"
#include "LoggerFactory.h"
#include "LoggerLibrary.h"
#include "BuildConfig.h"

int main() {

    auto version = std::to_string(VERSIONABLE_VERSION_PRIMARY) +
                             "." + std::to_string(VERSIONABLE_VERSION_SECONDARY) +
                             "." + std::to_string(VERSIONABLE_VERSION_PATCH);

    if (VERSIONABLE_SNAPSHOT) {

        version += "-SNAPSHOT";
    }

    argparse::ArgumentParser program("relog", version);
    program.add_argument("-v", "--version");
    return 0;
}
