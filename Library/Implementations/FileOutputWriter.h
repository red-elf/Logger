#ifndef LOGGER_FILEOUTPUTWRITER_H
#define LOGGER_FILEOUTPUTWRITER_H

#include <string>
#include <iostream>
#include <fstream>

#include "OutputWriter.h"

class FileOutputWriter : public OutputWriter {

public:

    void write(const std::string &content) override;

    void setFileName(const std::string &newFileName);

    [[nodiscard]] const std::string &getFileName() const;

private:

    std::string fileName = "out.txt";
};

#endif
