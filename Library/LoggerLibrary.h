#ifndef LOGGER_LOGGERLIBRARY_H
#define LOGGER_LOGGERLIBRARY_H

#include <string>
#include "LoggerConfig.h"

namespace LoggingSystemLibrary::Info {

    static std::string getVersion() {
        std::string majorVersion = std::to_string(LOGGER_VERSION_MAJOR);
        std::string minorVersion = std::to_string(LOGGER_VERSION_MINOR);
        return majorVersion + "." + minorVersion;
    }
}

#endif //LOGGER_LOGGERLIBRARY_H
