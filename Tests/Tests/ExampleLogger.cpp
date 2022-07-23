#include <list>

#include "ExampleLogger.h"
#include "LogLevel.h"

void ExampleLogger::logFull(
        const std::string &applicationId,
        const std::string &applicationVersion,
        long time,
        const LogLevel &level,
        const std::string &tag,
        const std::string &message,
        const std::list<std::string> &stackTrace
) {

    ++LOG_COUNT;
}
