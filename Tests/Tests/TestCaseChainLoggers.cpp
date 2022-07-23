#include <list>

#include "TestCaseChainLoggers.h"

#include "LoggerChained.h"
#include "ExampleLogger.h"

bool TestCaseChainLoggers::execute() {

    LoggerChained loggerChained;

    auto iterations = 100;
    ExampleLogger exampleLogger;
    ExampleLogger exampleLogger2;
    ExampleLogger exampleLogger3;

    loggerChained.addLogger(&exampleLogger);
    loggerChained.addLogger(&exampleLogger2);
    loggerChained.addLogger(&exampleLogger3);

    for (int x = 0; x < iterations; ++x) {

        auto mock = "logging";
        std::list<std::string> mockStacktrace;
        loggerChained.log(mock);
        loggerChained.log(LogLevel::debug, mock);
        loggerChained.log(mock, mock);
        loggerChained.log(mock, mockStacktrace);
        loggerChained.log(LogLevel::debug, mock, mock);
        loggerChained.log(LogLevel::debug, mock, mockStacktrace);
        loggerChained.log(mock, mock, mockStacktrace);
        loggerChained.log(LogLevel::debug, mock, mock, mockStacktrace);
        loggerChained.logFull(mock, mock, 0, LogLevel::debug, mock, mock, mockStacktrace);
    }

    if (ASSERT_EQUAL(3, loggerChained.getLoggersCount())) {

        auto count = 0;
        auto expected = 3 * (iterations * 9); // 9 is the number of method versions that we have.
        count += exampleLogger.LOG_COUNT;
        count += exampleLogger2.LOG_COUNT;
        count += exampleLogger3.LOG_COUNT;
        return ASSERT_EQUAL(expected, count);
    }
    return false;
}