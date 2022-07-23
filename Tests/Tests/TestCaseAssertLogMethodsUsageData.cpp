#include "TestCaseAssertLogMethodsUsageData.h"
#include "LoggerFactory.h"

LoggerFactory::LoggerCreateFunction TestCaseAssertLogMethodsUsageData::getExampleLoggerCreateFunction() {

    return exampleLoggerCreateFunction;
}
