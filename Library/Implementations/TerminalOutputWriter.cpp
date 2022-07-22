#include <string>
#include <iostream>

#include "TerminalOutputWriter.h"

void TerminalOutputWriter::write(const std::string &content) {

    std::cout << content;
}
