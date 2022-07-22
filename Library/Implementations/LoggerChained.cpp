#include <list>

#include "LoggerChained.h"

#include "Logger.h"
#include "LogLevel.h"

void LoggerChained::logFull(
        const std::string &applicationId,
        const std::string &applicationVersion,
        long time,
        const LogLevel &level,
        const std::string &tag,
        const std::string &message,
        const std::list<std::string> &stackTrace
) {

    for (Logger *logger : loggers) {

        logger->logFull(
                applicationId,
                applicationVersion,
                time,
                level,
                tag,
                message,
                stackTrace
        );
    }
}

void LoggerChained::addLogger(Logger *logger) {

    loggers.emplace_back(logger);
}

int LoggerChained::getLoggersCount() const {

    return loggers.size();
}
