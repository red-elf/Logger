#ifndef LOGGINGSYSTEM_TERMINALOUTPUTWRITER_H
#define LOGGINGSYSTEM_TERMINALOUTPUTWRITER_H

#include <string>

#include "OutputWriter.h"

class TerminalOutputWriter : public OutputWriter {

public:

    void write(const std::string &content) override;
};


#endif //LOGGINGSYSTEM_TERMINALOUTPUTWRITER_H
