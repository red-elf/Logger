#include <string>
#include <iostream>

#include "FileOutputWriter.h"

void FileOutputWriter::write(const std::string &content) {

    std::ofstream out;
    out.open(fileName, std::fstream::app);
    out << content;
    out.close();
}

void FileOutputWriter::setFileName(const std::string &newFileName) {

    fileName = newFileName;
}

const std::string &FileOutputWriter::getFileName() const {

    return fileName;
}
