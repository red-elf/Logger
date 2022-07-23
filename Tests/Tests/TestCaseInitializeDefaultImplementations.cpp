#include "TestCaseInitializeDefaultImplementations.h"

#include <iostream>
#include <string>

#include "TestCase.h"
#include "LoggerFactory.h"

bool TestCaseInitializeDefaultImplementations::execute() {

    int expectedDefaultImplementationCount = 1;
    LoggerFactory::initializeDefaultImplementations();
    int count = LoggerFactory::creators().size();
    return ASSERT_EQUAL(expectedDefaultImplementationCount, count);
}