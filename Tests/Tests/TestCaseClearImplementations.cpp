
#include "TestCaseClearImplementations.h"
#include "LoggerFactory.h"

bool TestCaseClearImplementations::execute() {

    LoggerFactory::clearImplementations();
    return ASSERT_TRUE(LoggerFactory::creators().empty());
}
