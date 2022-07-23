
#include "TestCaseRegisterImplementation.h"
#include "TestCaseRegisterImplementationData.h"
#include "LoggerFactory.h"

bool TestCaseRegisterImplementation::execute() {

    auto iterations = 2;
    auto loggerName = "ExampleLogger";
    auto expectedDefaultImplementationCount = 1;
    auto data = (TestCaseRegisterImplementationData *) testCaseData;

    LoggerFactory::clearImplementations();
    bool registered = false;
    for (int x = 0; x < iterations; ++x) {

        if (x == 0) {
            registered = ASSERT_TRUE(
                    LoggerFactory::registerImplementation(
                            loggerName, data->getExampleLoggerCreateFunction()
                    )
            );
        } else {
            ASSERT_TRUE(registered);
            registered = ASSERT_FALSE(
                    LoggerFactory::registerImplementation(
                            loggerName, data->getExampleLoggerCreateFunction()
                    )
            );
        }
    }

    int count = LoggerFactory::creators().size();
    return ASSERT_TRUE(registered && ASSERT_EQUAL(expectedDefaultImplementationCount, count));
}
