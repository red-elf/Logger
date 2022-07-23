#ifndef LOGGINGSYSTEM_TESTCASELOGGERSIMPLELINESCOUNT_H
#define LOGGINGSYSTEM_TESTCASELOGGERSIMPLELINESCOUNT_H

#include <string>

#include "TestCase.h"
#include "TestCaseData.h"
#include "DataTestCase.h"

class TestCaseLoggerSimpleLinesCount : public DataTestCase {

public:

    explicit TestCaseLoggerSimpleLinesCount(TestCaseData *testCaseData)
            : DataTestCase(testCaseData) {}

    bool execute() override;

    static const std::string &outFileName() {

        static const std::string &outFileName = "testOut.txt";
        return outFileName;
    }
};

#endif //LOGGINGSYSTEM_TESTCASELOGGERSIMPLELINESCOUNT_H
