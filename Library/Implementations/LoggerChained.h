#ifndef LOGGER_LOGGERCHAINED_H
#define LOGGER_LOGGERCHAINED_H

#include <list>
#include <string>

#include "Logger.h"
#include "LogLevel.h"

class LoggerChained : public Logger {

public:

    LoggerChained() = default;;

    void logFull(
            const std::string &applicationId,
            const std::string &applicationVersion,
            long time,
            const LogLevel &level,
            const std::string &tag,
            const std::string &message,
            const std::list<std::string> &stackTrace
    ) override;

    void addLogger(Logger *logger);

    [[nodiscard]] int getLoggersCount() const;

private:

    std::list<Logger *> loggers;
};


#endif //LOGGER_LOGGERCHAINED_H
