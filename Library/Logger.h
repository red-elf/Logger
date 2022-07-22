#ifndef LOGGINGSYSTEM_LOGGER_H
#define LOGGINGSYSTEM_LOGGER_H

#include <iostream>
#include <string>
#include <list>
#include <chrono>

#include "LogLevel.h"

class Logger {

private:

    std::string applicationId;
    std::string applicationVersion;

public:

    Logger();

    void log(
            const std::string &message
    );

    void log(
            const LogLevel &level,
            const std::string &message
    );

    void log(
            const std::string &tag,
            const std::string &message
    );

    void log(
            const std::string &message,
            const std::list<std::string> &stackTrace
    );

    void log(
            const LogLevel &level,
            const std::string &tag,
            const std::string &message
    );

    void log(
            const LogLevel &level,
            const std::string &message,
            const std::list<std::string> &stackTrace
    );

    void log(
            const std::string &tag,
            const std::string &message,
            const std::list<std::string> &stackTrace
    );


    void log(
            const LogLevel &level,
            const std::string &tag,
            const std::string &message,
            const std::list<std::string> &stackTrace
    );

    virtual void logFull(
            const std::string &applicationId,
            const std::string &applicationVersion,
            long time,
            const LogLevel &level,
            const std::string &tag,
            const std::string &message,
            const std::list<std::string> &stackTrace
    ) = 0;

    void setApplicationId(const std::string &id);

    void setApplicationVersion(const std::string &applicationVersion);

    [[nodiscard]] const std::string &getApplicationId() const;

    [[nodiscard]] const std::string &getApplicationVersion() const;

protected:

    static long getCurrentTime() {

        return std::chrono::duration_cast<std::chrono::milliseconds>(
                std::chrono::system_clock::now().time_since_epoch()).count();
    }
};

#endif //LOGGINGSYSTEM_LOGGER_H
