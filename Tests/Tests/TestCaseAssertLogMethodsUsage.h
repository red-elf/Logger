#ifndef LOGGINGSYSTEM_TESTCASEASSERTLOGMETHODSUSAGE_H
#define LOGGINGSYSTEM_TESTCASEASSERTLOGMETHODSUSAGE_H

#include <string>

#include "TestCase.h"
#include "TestCaseData.h"
#include "DataTestCase.h"

class TestCaseAssertLogMethodsUsage : public DataTestCase {

public:
    explicit TestCaseAssertLogMethodsUsage(TestCaseData *testCaseData)
            : DataTestCase(testCaseData) {}

    bool execute() override;
};


#endif // LOGGINGSYSTEM_TESTCASEASSERTLOGMETHODSUSAGE_H
