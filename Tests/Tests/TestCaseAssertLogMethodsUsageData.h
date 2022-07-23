#ifndef LOGGINGSYSTEM_TESTCASEASSERTLOGMETHODUSAGEDATA_H
#define LOGGINGSYSTEM_TESTCASEASSERTLOGMETHODUSAGEDATA_H

#include <string>

#include "TestCase.h"
#include "TestCaseData.h"
#include "DataTestCase.h"
#include "LoggerFactory.h"

class TestCaseAssertLogMethodsUsageData : public TestCaseData {

public:

    TestCaseAssertLogMethodsUsageData(
            const std::string &testCaseName,
            LoggerFactory::LoggerCreateFunction createFunction
    ) : TestCaseData(testCaseName) {

        exampleLoggerCreateFunction = createFunction;
    }

    LoggerFactory::LoggerCreateFunction getExampleLoggerCreateFunction();

private:

    LoggerFactory::LoggerCreateFunction exampleLoggerCreateFunction;
};


#endif // LOGGINGSYSTEM_TESTCASEASSERTLOGMETHODUSAGEDATA_H
