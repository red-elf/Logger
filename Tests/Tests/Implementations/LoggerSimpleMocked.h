#include <list>
#include <string>

#include "Logger.h"
#include "LogLevel.h"
#include "LoggerSimple.h"
#include "LoggerSimpleAbstract.h"

class LoggerSimpleMocked : public Logger, public LoggerSimpleAbstract {

public:

    LoggerSimpleMocked() = default;;

    void logFull(
            const std::string &applicationId,
            const std::string &applicationVersion,
            long time,
            const LogLevel &level,
            const std::string &tag,
            const std::string &message,
            const std::list<std::string> &stackTrace
    ) override;

    void setMockedTime(long timeToSet);

    void setOutputWriterFunction(LoggerSimple::OutputWriterFunction writerFunction);

    void setUsingDynamicTabs(bool value) override;

    void setTabWidthApplicationId(int value) override;

    void setTabWidthApplicationVersion(int value) override;

    void setTabWidthTime(int value) override;

    void setTabWidthTag(int value) override;

    void setShowTimeInNanos(bool value) override;

    void resetTabWidths() override;

    void resetDynamicTabs() override;

private:

    LoggerSimple logger;

    long mockedTime = 0;
};
