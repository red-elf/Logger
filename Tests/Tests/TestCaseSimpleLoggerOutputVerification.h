#ifndef LOGGINGSYSTEM_TESTCASESIMPLELOGGEROUTPUTVERIFICATION_H
#define LOGGINGSYSTEM_TESTCASESIMPLELOGGEROUTPUTVERIFICATION_H

#include <string>

#include "TestCase.h"
#include "TestCaseData.h"
#include "DataTestCase.h"

class TestCaseSimpleLoggerOutputVerification : public DataTestCase {

public:

    explicit TestCaseSimpleLoggerOutputVerification(TestCaseData *testCaseData)
            : DataTestCase(testCaseData) {}

    bool execute() override;
};

#endif //LOGGINGSYSTEM_TESTCASESIMPLELOGGEROUTPUTVERIFICATION_H
