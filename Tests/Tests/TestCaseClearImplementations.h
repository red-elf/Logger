#ifndef LOGGINGSYSTEM_TESTCASECLEARIMPLEMENTATIONS_H
#define LOGGINGSYSTEM_TESTCASECLEARIMPLEMENTATIONS_H

#include <string>

#include "TestCase.h"
#include "TestCaseData.h"
#include "DataTestCase.h"

class TestCaseClearImplementations : public DataTestCase {

public:
    explicit TestCaseClearImplementations(TestCaseData *testCaseData)
            : DataTestCase(testCaseData) {}

    bool execute() override;
};


#endif //LOGGINGSYSTEM_TESTCASECLEARIMPLEMENTATIONS_H
