#ifndef LOGGER_OUTPUTWRITER_H
#define LOGGER_OUTPUTWRITER_H

#include <string>

class OutputWriter {

public:

    virtual void write(const std::string &content) = 0;
};


#endif //LOGGER_OUTPUTWRITER_H
