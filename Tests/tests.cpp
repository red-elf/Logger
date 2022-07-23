#include <iostream>
#include <string>

#include "TestLogging.h"
#include "Tester.h"
#include "LoggerFactory.h"
#include "LoggerSimple.h"

#include "Tests/TestLoggerFactory.h"
#include "Tests/TestSimpleLogger.h"
#include "Tests/TestInitializeDefaultImplementations.h"
#include "Tests/TestLoggingMethods.h"
#include "Tests/TestChainedLogger.h"

using namespace TestingLibrary::Testing;
using namespace TestingLibrary::Logging;

Logger *obtainLogger() {

    static LoggerSimple logger;
    logger.setApplicationId("Logging System Library Tests");
    logger.setApplicationVersion("1.0");
    return &logger;
}

Logger *obtainExampleLogger() {

    static ExampleLogger exampleLogger;
    return &exampleLogger;
}

int main() {

    OUTPUT_WRITER_FUNCTION = [](const std::string &what, int priority) {

        auto logger = obtainLogger();
        LogLevel level;
        switch (priority) {
            case OUTPUT_WRITER_PRIORITY_STARTED:
                level = LogLevel::verbose;
                break;
            case OUTPUT_WRITER_PRIORITY_EXECUTED:
                level = LogLevel::debug;
                break;
            case OUTPUT_WRITER_PRIORITY_FAILED:
                level = LogLevel::error;
                break;
            case OUTPUT_WRITER_PRIORITY_TEST_CASE_PASSED:
                level = LogLevel::verbose;
                break;
            case OUTPUT_WRITER_PRIORITY_TEST_CASE_FAILED:
                level = LogLevel::error;
                break;
            case OUTPUT_WRITER_PRIORITY_ASSERT_FAILED:
                level = LogLevel::error;
                break;
            default:
                level = LogLevel::verbose;
        }
        logger->log(level, what);
    };

    TestLoggerFactory testLoggerFactory(obtainExampleLogger);
    TestLoggingMethods testLoggingMethods(obtainExampleLogger);
    TestInitializeDefaultImplementations testInitializeDefaultImplementations;
    TestSimpleLogger testSimpleLogger;
    TestChainedLogger testChainedLogger;

    REGISTER_TEST(&testLoggerFactory);
    REGISTER_TEST(&testLoggingMethods);
    REGISTER_TEST(&testInitializeDefaultImplementations);
    REGISTER_TEST(&testSimpleLogger);
    REGISTER_TEST(&testChainedLogger);

    return RUN_TESTS();
}
