#include <string>
#include <iostream>

#include "TestInitializeDefaultImplementations.h"
#include "Logger.h"
#include "LoggerFactory.h"
#include "TestCaseData.h"
#include "TestCaseClearImplementations.h"
#include "TestCaseInitializeDefaultImplementations.h"

std::string TestInitializeDefaultImplementations::name() {

    return "Initialize Default Implementations test";
}

void TestInitializeDefaultImplementations::execute() {

    TestCaseData testCaseClearImplementationsData("Clear Implementations");
    TestCaseClearImplementations testCaseClearImplementations(&testCaseClearImplementationsData);

    TestCaseData testCaseInitializeDefaultImplementationsData("Initialize Default Implementations");
    TestCaseInitializeDefaultImplementations testCaseInitializeDefaultImplementations(
            &testCaseInitializeDefaultImplementationsData
    );

    EXECUTE_TEST_CASE(&testCaseClearImplementations);
    EXECUTE_TEST_CASE(&testCaseInitializeDefaultImplementations);
    EXECUTE_TEST_CASE(&testCaseClearImplementations);
}
