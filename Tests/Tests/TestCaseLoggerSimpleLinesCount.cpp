#include "TestCaseLoggerSimpleLinesCount.h"

#include <iostream>
#include <string>

#include "Logger.h"
#include "TestCase.h"
#include "LoggerFactory.h"

#include "FileOutputWriter.h"

bool TestCaseLoggerSimpleLinesCount::execute() {

    auto outputWriterFunction = [](const std::string &what) {

        FileOutputWriter outputWriter;
        outputWriter.setFileName(outFileName());
        outputWriter.write(what);
    };

    Logger *logger = LoggerFactory::create(LoggerFactoryImplementationNames::IMPL_LOGGER_SIMPLE());
    auto simpleLogger = (LoggerSimple *) logger;

    const char *cstr = outFileName().c_str();
    std::remove(cstr);
    simpleLogger->setOutputWriterFunction(outputWriterFunction);

    auto count = 0;
    auto iterations = 1000;
    for (int x = 0; x < iterations; ++x) {

        auto mock = "logging";
        std::list<std::string> mockStacktrace;
        simpleLogger->log(mock);
        simpleLogger->log(LogLevel::debug, mock);
        simpleLogger->log(mock, mock);
        simpleLogger->log(mock, mockStacktrace);
        simpleLogger->log(LogLevel::debug, mock, mock);
        simpleLogger->log(LogLevel::debug, mock, mockStacktrace);
        simpleLogger->log(mock, mock, mockStacktrace);
        simpleLogger->log(LogLevel::debug, mock, mock, mockStacktrace);
        simpleLogger->logFull(mock, mock, 0, LogLevel::debug, mock, mock, mockStacktrace);
    }
    std::string line;
    std::ifstream testFile(outFileName());
    while (std::getline(testFile, line)) {
        ++count;
    }
    auto expectedCount = (iterations * 9); // 9 is number of methods that we are  triggering per iteration.

    return ASSERT_TRUE(
            ASSERT_EQUAL(expectedCount, count) &&
            ASSERT_TRUE(std::remove(cstr) == 0)
    );
}