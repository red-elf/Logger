#ifndef LOGGINGSYSTEM_LOGGERSIMPLE_H
#define LOGGINGSYSTEM_LOGGERSIMPLE_H

#include <list>
#include <string>
#include <map>

#include "Logger.h"
#include "LoggerSimpleAbstract.h"

class LoggerSimple : public Logger, public LoggerSimpleAbstract {

public:

    typedef void (*OutputWriterFunction)(const std::string &what);

    LoggerSimple();

    void logFull(
            const std::string &applicationId,
            const std::string &applicationVersion,
            long time,
            const LogLevel &level,
            const std::string &tag,
            const std::string &message,
            const std::list<std::string> &stackTrace
    ) override;

    [[nodiscard]] bool isUsingDynamicTabs() const;

    [[nodiscard]] int getTabWidthApplicationId() const;

    [[nodiscard]] int getTabWidthApplicationVersion() const;

    [[nodiscard]] int getTabWidthTime() const;

    [[nodiscard]] int getTabWidthTag() const;

    [[nodiscard]] bool isShowingTimeInNanos() const;

    void setUsingDynamicTabs(bool value) override;

    void setTabWidthApplicationId(int value) override;

    void setTabWidthApplicationVersion(int value) override;

    void setTabWidthTime(int value) override;

    void setTabWidthTag(int value) override;

    void setShowTimeInNanos(bool value) override;

    void resetTabWidths() override;

    void resetDynamicTabs() override;

    void setOutputWriterFunction(OutputWriterFunction writerFunction);

private:

    OutputWriterFunction outputWriterFunction;

    const int tabWidthApplicationIdDefault = 30;
    const int tabWidthApplicationVersionDefault = 6;
    const int tabWidthTimeDefault = 20;
    const int tabWidthTagDefault = 5;
    const int maximalAllowableWidth = 50;

    bool useDynamicTabs = true;
    bool showTimeInNanos = false;
    int tabWidthApplicationId = tabWidthApplicationIdDefault;
    int tabWidthApplicationVersion = tabWidthApplicationVersionDefault;
    int tabWidthTime = tabWidthTimeDefault;
    int tabWidthTag = tabWidthTagDefault;

    const std::string keyApplicationId = "applicationId";
    const std::string keyApplicationVersion = "applicationVersion";
    const std::string keyTime = "time";
    const std::string keyTag = "tag";
    const std::string keyNoKey = "noKey";

    const std::string defaultEnding = " ...";
    const std::string defaultEmptyCell = "- - -";
    std::map<std::string, int> currentTabWidths;
    std::map<int, std::string> cachedSpaces;

    static std::string getInTab(const std::string &what);

    std::string getTrimmed(
            const std::string &what,
            int limitTo,
            const std::string &column,
            const std::string &ending
    );

    std::string getTrimmed(
            const std::string &what,
            int limitTo,
            const std::string &column
    );

    std::string getInTabTrimmed(
            const std::string &what,
            int limitTo,
            const std::string &column,
            const std::string &ending
    );

    std::string getInTabTrimmed(
            const std::string &what,
            int limitTo,
            const std::string &column
    );

    [[nodiscard]] std::string getWrappedEmpty(const std::string &what) const;
};


#endif //LOGGINGSYSTEM_LOGGERSIMPLE_H
