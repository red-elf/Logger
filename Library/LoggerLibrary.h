#ifndef LOGGER_LOGGERLIBRARY_H
#define LOGGER_LOGGERLIBRARY_H

#include <string>
#include "BuildConfig.h"

namespace LoggerLibrary::Info {

    static std::string getVersion() {
        std::string majorVersion = std::to_string(VERSIONABLE_VERSION_PRIMARY);
        std::string minorVersion = std::to_string(VERSIONABLE_VERSION_SECONDARY);
        std::string patchVersion = std::to_string(VERSIONABLE_VERSION_PATCH);
        return majorVersion + "." + minorVersion + "." + patchVersion;
    }
}

#endif //LOGGER_LOGGERLIBRARY_H
