#ifndef LOGGINGSYSTEM_TESTCASECHAINLOGGERS_H
#define LOGGINGSYSTEM_TESTCASECHAINLOGGERS_H

#include "TestCase.h"
#include "TestCaseData.h"
#include "DataTestCase.h"

class TestCaseChainLoggers : public DataTestCase {

public:
    explicit TestCaseChainLoggers(TestCaseData *testCaseData)
            : DataTestCase(testCaseData) {}

    bool execute() override;
};


#endif //LOGGINGSYSTEM_TESTCASECHAINLOGGERS_H
