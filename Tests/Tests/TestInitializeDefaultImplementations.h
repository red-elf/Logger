#ifndef LOGGINGSYSTEM_TESTINITIALIZEDEFAULTIMPLEMENTATIONS_H
#define LOGGINGSYSTEM_TESTINITIALIZEDEFAULTIMPLEMENTATIONS_H

#include "Test.h"
#include "Logger.h"

class TestInitializeDefaultImplementations : public Test {

public:
    TestInitializeDefaultImplementations() : Test() {

    };

    void execute() override;

    std::string name() override;
};

#endif //LOGGINGSYSTEM_TESTINITIALIZEDEFAULTIMPLEMENTATIONS_H
