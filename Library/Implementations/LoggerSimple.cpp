#include <iostream>
#include <list>
#include <string>
#include <map>
#include <ctime>

#include "LoggerSimple.h"
#include "Color.h"
#include "LoggerColors.h"
#include "TerminalOutputWriter.h"

LoggerSimple::LoggerSimple() {

    outputWriterFunction = [](const std::string &what) {

        TerminalOutputWriter outputWriter;
        outputWriter.write(what);
    };
}

void LoggerSimple::logFull(
        const std::string &applicationId,
        const std::string &applicationVersion,
        long time,
        const LogLevel &level,
        const std::string &tag,
        const std::string &message,
        const std::list<std::string> &stackTrace
) {
    std::string stackTracePrint;
    if (!stackTrace.empty()) {
        stackTracePrint += '\n';
        std::string whitespace = getTrimmed(
                " ",
                tabWidthApplicationId + (int) defaultEnding.size(),
                keyNoKey
        );
        int x = 0;
        for (const std::string &item : stackTrace) {
            ++x;
            stackTracePrint += whitespace + item;
            if (x < stackTrace.size()) {
                stackTracePrint += '\n';
            }
        }
    }

    auto millis = time / 1000;
    auto tt = static_cast<time_t>(millis);
    char dateFormated[100];
    strftime(dateFormated, sizeof(dateFormated), "%Y-%m-%d %H:%M:%S", std::localtime(&tt));
    std::string dateFormatedStr(dateFormated);
    std::string printableTime = dateFormatedStr;
    if (showTimeInNanos) {
        printableTime += " :: " + std::to_string(time);
    }
    auto output = getInTabTrimmed(getWrappedEmpty(printableTime), tabWidthTime, keyTime)
                  + getInTabTrimmed(getWrappedEmpty(applicationId), tabWidthApplicationId, keyApplicationId)
                  + getInTabTrimmed(getWrappedEmpty(applicationVersion), tabWidthApplicationVersion,
                                    keyApplicationVersion)
                  + getInTabTrimmed(getWrappedEmpty(tag), tabWidthTag, keyTag)
                  + getWrappedEmpty(message)
                  + stackTracePrint;


    Color color(0);
    switch (level) {
        case LogLevel::debug:
            color = LoggerColors::getColor(LoggerColors::COLOR_YELLOW);
            break;
        case LogLevel::info:
            color = LoggerColors::getColor(LoggerColors::COLOR_CYAN);
            break;
        case LogLevel::warning:
            color = LoggerColors::getColor(LoggerColors::COLOR_PURPLE);
            break;
        case LogLevel::error:
            color = LoggerColors::getColor(LoggerColors::COLOR_RED);
            break;
        default:
            color = LoggerColors::getColor(LoggerColors::COLOR_DEFAULT);
    }

    outputWriterFunction(LoggerColors::getColored(output, color) + "\n");
}

std::string LoggerSimple::getInTab(const std::string &what) {

    return what + " | ";
}

std::string LoggerSimple::getTrimmed(
        const std::string &what,
        int limitTo,
        const std::string &column,
        const std::string &ending
) {
    if (useDynamicTabs) {
        limitTo = maximalAllowableWidth - (int) ending.size();
    }
    if (what.size() < limitTo) {
        auto toReturn = what;
        auto count = limitTo - (int) what.size();

        if (useDynamicTabs && column != keyNoKey) {
            auto currentMaximum = 0;
            auto it = currentTabWidths.find(column);
            if (it != currentTabWidths.end()) {
                currentMaximum = it->second;
                if (currentMaximum < what.size()) {
                    currentMaximum = what.size();
                    currentTabWidths.insert_or_assign(column, currentMaximum);
                }
            } else {
                currentMaximum = what.size();
                currentTabWidths.insert_or_assign(column, currentMaximum);
            }
            count = currentMaximum - what.size();
        }

        auto it = cachedSpaces.find(count);
        if (it != cachedSpaces.end()) {
            toReturn += it->second;
        } else {
            std::string spaces;
            for (int i = 0; i < count; i++) {
                spaces += " ";
            }
            toReturn += spaces;
            cachedSpaces.insert_or_assign(count, spaces);
        }

        return toReturn;
    }
    if (what.size() > limitTo) {
        if (limitTo < ending.size()) {
            return what.substr(0, limitTo) + ending;
        } else {
            return what.substr(0, limitTo - ending.size() - 1) + ending;
        }
    }
    return what;
}

std::string LoggerSimple::getTrimmed(
        const std::string &what,
        int limitTo,
        const std::string &column
) {

    return getTrimmed(what, limitTo, column, defaultEnding);
}

std::string LoggerSimple::getInTabTrimmed(
        const std::string &what,
        int limitTo,
        const std::string &column,
        const std::string &ending
) {

    return getInTab(getTrimmed(what, limitTo, column, ending));
}

std::string LoggerSimple::getInTabTrimmed(
        const std::string &what,
        int limitTo,
        const std::string &column
) {

    return getInTabTrimmed(what, limitTo, column, defaultEnding);
}

bool LoggerSimple::isUsingDynamicTabs() const {

    return useDynamicTabs;
}

int LoggerSimple::getTabWidthApplicationId() const {

    return tabWidthApplicationId;
}

int LoggerSimple::getTabWidthApplicationVersion() const {

    return tabWidthApplicationVersion;
}

int LoggerSimple::getTabWidthTime() const {

    return tabWidthTime;
}

int LoggerSimple::getTabWidthTag() const {

    return tabWidthTag;
}

bool LoggerSimple::isShowingTimeInNanos() const {

    return showTimeInNanos;
}

void LoggerSimple::setTabWidthApplicationId(int value) {

    tabWidthApplicationId = value;
}

void LoggerSimple::setTabWidthApplicationVersion(int value) {

    tabWidthApplicationVersion = value;
}

void LoggerSimple::setTabWidthTime(int value) {

    tabWidthTime = value;
}

void LoggerSimple::setTabWidthTag(int value) {

    tabWidthTag = value;
}

void LoggerSimple::setShowTimeInNanos(bool value) {

    showTimeInNanos = value;
}

void LoggerSimple::setUsingDynamicTabs(bool value) {

    useDynamicTabs = value;
}

void LoggerSimple::setOutputWriterFunction(OutputWriterFunction writerFunction) {

    outputWriterFunction = writerFunction;
}

void LoggerSimple::resetTabWidths() {
    tabWidthApplicationId = tabWidthApplicationIdDefault;
    tabWidthApplicationVersion = tabWidthApplicationVersionDefault;
    tabWidthTime = tabWidthTimeDefault;
    tabWidthTag = tabWidthTagDefault;
}

std::string LoggerSimple::getWrappedEmpty(const std::string &what) const {
    if (what.empty()) {
        return defaultEmptyCell;
    }
    return what;
}

void LoggerSimple::resetDynamicTabs() {
    currentTabWidths.clear();
}
