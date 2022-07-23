#ifndef LOGGINGSYSTEM_TESTLOGGINGMETHODS_H
#define LOGGINGSYSTEM_TESTLOGGINGMETHODS_H

#include <string>

#include "Test.h"
#include "ExampleLogger.h"
#include "LoggerFactory.h"

class TestLoggingMethods : public Test {

public:
    explicit TestLoggingMethods(LoggerFactory::LoggerCreateFunction createFunction)
            : Test() {

        exampleLoggerCreateFunction = createFunction;
    };

    void execute() override;

    std::string name() override;

    Logger *obtainLogger();

private:

    LoggerFactory::LoggerCreateFunction exampleLoggerCreateFunction;
};


#endif // LOGGINGSYSTEM_TESTLOGGINGMETHODS_H
