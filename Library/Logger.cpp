#include <iostream>
#include <string>
#include <list>

#include "Logger.h"
#include "LogLevel.h"

Logger::Logger() {

    applicationId = "";
    applicationVersion = "";
}

void Logger::setApplicationId(const std::string &id) {

    applicationId = id;
}

void Logger::setApplicationVersion(const std::string &version) {

    applicationVersion = version;
}

const std::string &Logger::getApplicationId() const {

    return applicationId;
}

const std::string &Logger::getApplicationVersion() const {

    return applicationVersion;
}

void Logger::log(
        const std::string &message
) {

    std::list<std::string> emptyList;
    logFull(
            getApplicationId(),
            getApplicationVersion(),
            getCurrentTime(),
            LogLevel::verbose,
            "",
            message,
            emptyList
    );
}

void Logger::log(
        const LogLevel &level,
        const std::string &message
) {

    std::list<std::string> emptyList;
    logFull(
            getApplicationId(),
            getApplicationVersion(),
            getCurrentTime(),
            level,
            "",
            message,
            emptyList
    );
}

void Logger::log(
        const std::string &tag,
        const std::string &message
) {

    std::list<std::string> emptyList;
    logFull(
            getApplicationId(),
            getApplicationVersion(),
            getCurrentTime(),
            LogLevel::verbose,
            tag,
            message,
            emptyList
    );
}

void Logger::log(
        const LogLevel &level,
        const std::string &tag,
        const std::string &message
) {

    std::list<std::string> emptyList;
    logFull(
            getApplicationId(),
            getApplicationVersion(),
            getCurrentTime(),
            level,
            tag,
            message,
            emptyList
    );
}

void Logger::log(
        const std::string &message,
        const std::list<std::string> &stackTrace
) {

    logFull(
            getApplicationId(),
            getApplicationVersion(),
            getCurrentTime(),
            LogLevel::verbose,
            "",
            message,
            stackTrace
    );
}

void Logger::log(
        const LogLevel &level,
        const std::string &message,
        const std::list<std::string> &stackTrace
) {

    logFull(
            getApplicationId(),
            getApplicationVersion(),
            getCurrentTime(),
            level,
            "",
            message,
            stackTrace
    );
}

void Logger::log(
        const std::string &tag,
        const std::string &message,
        const std::list<std::string> &stackTrace
) {

    logFull(
            getApplicationId(),
            getApplicationVersion(),
            getCurrentTime(),
            LogLevel::verbose,
            tag,
            message,
            stackTrace
    );
}

void Logger::log(
        const LogLevel &level,
        const std::string &tag,
        const std::string &message,
        const std::list<std::string> &stackTrace
) {

    logFull(
            getApplicationId(),
            getApplicationVersion(),
            getCurrentTime(),
            level,
            tag,
            message,
            stackTrace
    );
}
