#ifndef LOGGINGSYSTEM_TESTCASEINITIALIZEDEFAULTIMPLEMENTATIONS_H
#define LOGGINGSYSTEM_TESTCASEINITIALIZEDEFAULTIMPLEMENTATIONS_H

#include <string>

#include "TestCase.h"
#include "TestCaseData.h"
#include "DataTestCase.h"

class TestCaseInitializeDefaultImplementations : public DataTestCase {

public:
    explicit TestCaseInitializeDefaultImplementations(TestCaseData *testCaseData)
            : DataTestCase(testCaseData) {}

    bool execute() override;
};


#endif //LOGGINGSYSTEM_TESTCASEINITIALIZEDEFAULTIMPLEMENTATIONS_H
