#ifndef LOGGER_COLOR_H
#define LOGGER_COLOR_H

#include <string>

class Color {

public:

    explicit Color(int value);

    int getColor();

    std::string getColorString();

private:

    int color;
};

#endif //LOGGER_COLOR_H
