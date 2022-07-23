#ifndef LOGGINGSYSTEM_TESTSIMPLELOGGER_H
#define LOGGINGSYSTEM_TESTSIMPLELOGGER_H

#include "Test.h"
#include "Logger.h"

class TestSimpleLogger : public Test {

public:

    explicit TestSimpleLogger() : Test() {};

    void execute() override;

    std::string name() override;
};


#endif //LOGGINGSYSTEM_TESTSIMPLELOGGER_H
