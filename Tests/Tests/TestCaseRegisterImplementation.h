#ifndef LOGGINGSYSTEM_TESTCASEREGISTERIMPLEMENTATION_H
#define LOGGINGSYSTEM_TESTCASEREGISTERIMPLEMENTATION_H

#include <string>

#include "TestCase.h"
#include "TestCaseData.h"
#include "DataTestCase.h"

class TestCaseRegisterImplementation : public DataTestCase {

public:
    explicit TestCaseRegisterImplementation(TestCaseData *testCaseData)
            : DataTestCase(testCaseData) {}

    bool execute() override;
};


#endif // LOGGINGSYSTEM_TESTCASEREGISTERIMPLEMENTATION_H
