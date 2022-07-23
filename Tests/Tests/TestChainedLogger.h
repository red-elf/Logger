#ifndef LOGGINGSYSTEM_TESTCHAINEDLOGGER_H
#define LOGGINGSYSTEM_TESTCHAINEDLOGGER_H

#include "Test.h"
#include "Logger.h"

class TestChainedLogger : public Test {

public:

    explicit TestChainedLogger() : Test() {};

    void execute() override;

    std::string name() override;
};


#endif //LOGGINGSYSTEM_TESTCHAINEDLOGGER_H
