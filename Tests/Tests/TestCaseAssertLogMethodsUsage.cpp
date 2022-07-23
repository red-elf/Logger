#include <string>

#include "TestCaseAssertLogMethodsUsage.h"
#include "TestCaseAssertLogMethodsUsageData.h"

#include "LoggerFactory.h"
#include "ExampleLogger.h"

bool TestCaseAssertLogMethodsUsage::execute() {

    auto *data = (TestCaseAssertLogMethodsUsageData *) testCaseData;

    auto count = 0;
    auto iterations = 1000;
    auto loggerName = "ExampleLogger";
    LoggerFactory::registerImplementation(
            loggerName,
            data->getExampleLoggerCreateFunction()
    );
    auto logger = LoggerFactory::create(loggerName);
    for (int x = 0; x < iterations; ++x) {

        auto mock = "logging";
        std::list<std::string> mockStacktrace;
        logger->log(mock);
        logger->log(LogLevel::debug, mock);
        logger->log(mock, mock);
        logger->log(mock, mockStacktrace);
        logger->log(LogLevel::debug, mock, mock);
        logger->log(LogLevel::debug, mock, mockStacktrace);
        logger->log(mock, mock, mockStacktrace);
        logger->log(LogLevel::debug, mock, mock, mockStacktrace);
        logger->logFull(mock, mock, 0, LogLevel::debug, mock, mock, mockStacktrace);
    }

    auto logger2 = dynamic_cast<ExampleLogger *>(logger);
    count = logger2->LOG_COUNT;
    auto expectedCount = (iterations * 9); // 9 is number of methods that we are  triggering per iteration.
    return ASSERT_EQUAL(expectedCount, count);
}
