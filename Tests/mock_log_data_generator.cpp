#include <fstream>
#include <iostream>

#include "Tests/MockLogDataGenerator.h"

using namespace LoggerLibrary::MockLogDataGenerator;

int main() {

    std::cout << "Generating mock data. Please wait!" << '\n';
    if (generateLogData(true)) {
        std::cout << "Mock data generated." << '\n';
        return 0;
    }
    std::cerr << "Mock data generating failed." << '\n';
    return 1;
}
