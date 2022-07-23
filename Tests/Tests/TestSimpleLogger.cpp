#include <iostream>

#include "TestSimpleLogger.h"
#include "TestCaseClearImplementations.h"
#include "TestCaseInitializeDefaultImplementations.h"
#include "TestCaseLoggerSimpleLinesCount.h"
#include "TestCaseSimpleLoggerOutputVerification.h"

std::string TestSimpleLogger::name() {

    return "Simple Logger test";
}

void TestSimpleLogger::execute() {

    TestCaseData testCaseClearImplementationsData("Clear Implementations");
    TestCaseClearImplementations testCaseClearImplementations(&testCaseClearImplementationsData);

    TestCaseData testCaseInitializeDefaultImplementationsData("Initialize Default Implementations");
    TestCaseInitializeDefaultImplementations testCaseInitializeDefaultImplementations(
            &testCaseInitializeDefaultImplementationsData
    );

    TestCaseData testCaseLoggerSimpleLinesCountData("Simple Logger Lines Count");
    TestCaseLoggerSimpleLinesCount testCaseLoggerSimpleLinesCount(&testCaseLoggerSimpleLinesCountData);

    TestCaseData testCaseSimpleLogsOutputVerificationData("Simple Logs Output Verification");
    TestCaseSimpleLoggerOutputVerification testCaseSimpleLogsOutputVerification(
            &testCaseSimpleLogsOutputVerificationData);

    EXECUTE_TEST_CASE(&testCaseClearImplementations);
    EXECUTE_TEST_CASE(&testCaseInitializeDefaultImplementations);
    EXECUTE_TEST_CASE(&testCaseLoggerSimpleLinesCount);
    EXECUTE_TEST_CASE(&testCaseClearImplementations);
    EXECUTE_TEST_CASE(&testCaseSimpleLogsOutputVerification);
}
