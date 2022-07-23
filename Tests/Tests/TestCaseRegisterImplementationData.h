#ifndef LOGGINGSYSTEM_TESTCASEREGISTERIMPLEMENTATIONDATA_H
#define LOGGINGSYSTEM_TESTCASEREGISTERIMPLEMENTATIONDATA_H

#include <string>

#include "TestCase.h"
#include "TestCaseData.h"
#include "DataTestCase.h"
#include "LoggerFactory.h"

class TestCaseRegisterImplementationData : public TestCaseData {

public:

    TestCaseRegisterImplementationData(
            const std::string &testCaseName,
            LoggerFactory::LoggerCreateFunction createFunction
    ) : TestCaseData(testCaseName) {

        exampleLoggerCreateFunction = createFunction;
    }

    LoggerFactory::LoggerCreateFunction getExampleLoggerCreateFunction();

private:

    LoggerFactory::LoggerCreateFunction exampleLoggerCreateFunction;
};


#endif // LOGGINGSYSTEM_TESTCASEREGISTERIMPLEMENTATIONDATA_H
