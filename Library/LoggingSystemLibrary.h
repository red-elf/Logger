#ifndef LOGGER_LOGGINGSYSTEMLIBRARY_H
#define LOGGER_LOGGINGSYSTEMLIBRARY_H

#include <string>
#include "LoggerConfig.h"

namespace LoggingSystemLibrary::Info {

    static std::string getVersion() {
        std::string majorVersion = std::to_string(LoggingSystemLibrary_VERSION_MAJOR);
        std::string minorVersion = std::to_string(LoggingSystemLibrary_VERSION_MINOR);
        return majorVersion + "." + minorVersion;
    }
}

#endif //LOGGER_LOGGINGSYSTEMLIBRARY_H
