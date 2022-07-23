#include <list>

#include "TestLoggerFactory.h"
#include "TestCaseData.h"

#include "TestCaseClearImplementations.h"
#include "TestCaseRegisterImplementation.h"
#include "TestCaseRegisterImplementationData.h"

std::string TestLoggerFactory::name() {

    return "Logger Factory test";
}

void TestLoggerFactory::execute() {

    TestCaseData testCaseClearImplementationsData("Clear Implementations");
    TestCaseClearImplementations testCaseClearImplementations(&testCaseClearImplementationsData);

    TestCaseRegisterImplementationData testCaseRegisterImplementationData(
            "Register Implementation", exampleLoggerCreateFunction
    );
    TestCaseRegisterImplementation testCaseRegisterImplementation(&testCaseRegisterImplementationData);

    EXECUTE_TEST_CASE(&testCaseClearImplementations);
    EXECUTE_TEST_CASE(&testCaseRegisterImplementation);
    EXECUTE_TEST_CASE(&testCaseClearImplementations);
}
