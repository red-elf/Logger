#ifndef LOGGINGSYSTEM_COLOR_H
#define LOGGINGSYSTEM_COLOR_H

#include <string>

class Color {

public:

    explicit Color(int value);

    int getColor();

    std::string getColorString();

private:

    int color;
};

#endif //LOGGINGSYSTEM_COLOR_H
