#ifndef LOGGER_TERMINALOUTPUTWRITER_H
#define LOGGER_TERMINALOUTPUTWRITER_H

#include <string>

#include "OutputWriter.h"

class TerminalOutputWriter : public OutputWriter {

public:

    void write(const std::string &content) override;
};


#endif //LOGGER_TERMINALOUTPUTWRITER_H
