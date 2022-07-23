#include <iostream>

#include "TestChainedLogger.h"
#include "TestCaseData.h"

#include "TestCaseChainLoggers.h"

std::string TestChainedLogger::name() {

    return "Chained Logger test";
}

void TestChainedLogger::execute() {

    TestCaseData testCaseChainLoggersData("Chain Loggers");
    TestCaseChainLoggers testCaseChainLoggers(&testCaseChainLoggersData);

    EXECUTE_TEST_CASE(&testCaseChainLoggers);
}
