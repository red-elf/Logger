#ifndef LOGGINGSYSTEM_TESTLOGGERFACTORY_H
#define LOGGINGSYSTEM_TESTLOGGERFACTORY_H

#include <string>

#include "Test.h"
#include "ExampleLogger.h"
#include "LoggerFactory.h"

class TestLoggerFactory : public Test {

public:
    explicit TestLoggerFactory(LoggerFactory::LoggerCreateFunction createFunction)
            : Test() {

        exampleLoggerCreateFunction = createFunction;
    };

    void execute() override;

    std::string name() override;

    Logger *obtainLogger();

private:

    LoggerFactory::LoggerCreateFunction exampleLoggerCreateFunction;
};


#endif //LOGGINGSYSTEM_TESTLOGGERFACTORY_H
