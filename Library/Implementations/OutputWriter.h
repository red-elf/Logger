#ifndef LOGGINGSYSTEM_OUTPUTWRITER_H
#define LOGGINGSYSTEM_OUTPUTWRITER_H

#include <string>

class OutputWriter {

public:

    virtual void write(const std::string &content) = 0;
};


#endif //LOGGINGSYSTEM_OUTPUTWRITER_H
