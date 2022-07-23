#ifndef LOGGINGSYSTEM_EXAMPLELOGGER_H
#define LOGGINGSYSTEM_EXAMPLELOGGER_H

#include <string>
#include <list>

#include "Logger.h"
#include "LogLevel.h"

class ExampleLogger : public Logger {

public:

    int LOG_COUNT = 0;

    void logFull(
            const std::string &applicationId,
            const std::string &applicationVersion,
            long time,
            const LogLevel &level,
            const std::string &tag,
            const std::string &message,
            const std::list<std::string> &stackTrace
    ) override;
};


#endif //LOGGINGSYSTEM_EXAMPLELOGGER_H
