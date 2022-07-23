#include <iostream>
#include <list>
#include <string>
#include <map>
#include <ctime>

#include "LoggerSimpleMocked.h"
#include "LoggerSimple.h"

void LoggerSimpleMocked::logFull(
        const std::string &applicationId,
        const std::string &applicationVersion,
        long time,
        const LogLevel &level,
        const std::string &tag,
        const std::string &message,
        const std::list<std::string> &stackTrace
) {

    long timeToSet = time;
    if (mockedTime > 0) {
        timeToSet = mockedTime;
    }

    logger.logFull(
            applicationId,
            applicationVersion,
            timeToSet,
            level,
            tag,
            message,
            stackTrace
    );
}

void LoggerSimpleMocked::setMockedTime(long timeToSet) {

    mockedTime = timeToSet;
}

void LoggerSimpleMocked::setOutputWriterFunction(LoggerSimple::OutputWriterFunction writerFunction) {

    logger.setOutputWriterFunction(writerFunction);
}

void LoggerSimpleMocked::setTabWidthApplicationId(int value) {

    logger.setTabWidthApplicationId(value);
}

void LoggerSimpleMocked::setTabWidthApplicationVersion(int value) {

    logger.setTabWidthApplicationVersion(value);
}

void LoggerSimpleMocked::setTabWidthTime(int value) {

    logger.setTabWidthTime(value);
}

void LoggerSimpleMocked::setTabWidthTag(int value) {

    logger.setTabWidthTag(value);
}

void LoggerSimpleMocked::setShowTimeInNanos(bool value) {

    logger.setShowTimeInNanos(value);
}

void LoggerSimpleMocked::setUsingDynamicTabs(bool value) {

    logger.setUsingDynamicTabs(value);
}


void LoggerSimpleMocked::resetTabWidths() {

    logger.resetTabWidths();
}

void LoggerSimpleMocked::resetDynamicTabs() {

    logger.resetDynamicTabs();
}