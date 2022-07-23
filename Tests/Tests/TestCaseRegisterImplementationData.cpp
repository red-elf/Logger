#include "TestCaseRegisterImplementationData.h"
#include "LoggerFactory.h"

LoggerFactory::LoggerCreateFunction TestCaseRegisterImplementationData::getExampleLoggerCreateFunction() {

    return exampleLoggerCreateFunction;
}
