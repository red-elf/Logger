#include <string>

#include "TestCaseData.h"
#include "TestLoggingMethods.h"
#include "TestCaseClearImplementations.h"
#include "TestCaseAssertLogMethodsUsage.h"
#include "TestCaseAssertLogMethodsUsageData.h"

std::string TestLoggingMethods::name() {

    return "Logging Methods test";
}

void TestLoggingMethods::execute() {

    TestCaseData testCaseClearImplementationsData("Clear Implementations");
    TestCaseClearImplementations testCaseClearImplementations(&testCaseClearImplementationsData);

    TestCaseAssertLogMethodsUsageData testCaseRegisterImplementationData(
            "Assert Log Methods Usage", exampleLoggerCreateFunction
    );
    TestCaseAssertLogMethodsUsage testCaseAssertLogMethodsUsage(&testCaseRegisterImplementationData);

    EXECUTE_TEST_CASE(&testCaseClearImplementations);
    EXECUTE_TEST_CASE(&testCaseAssertLogMethodsUsage);
    EXECUTE_TEST_CASE(&testCaseClearImplementations);
}
