#ifndef LOGGINGSYSTEM_LOGGERCOLORS_H
#define LOGGINGSYSTEM_LOGGERCOLORS_H

#include <string>

#include "Color.h"

namespace LoggerColors {

    static int COLOR_RED = 31;
    static int COLOR_CYAN = 36;
    static int COLOR_YELLOW = 33;
    static int COLOR_PURPLE = 35;
    static int COLOR_DEFAULT = 0;

    static std::string getColored(const std::string &what, Color &color) {
        const std::string closing = "\033[0m";
        Color colorDefault(LoggerColors::COLOR_DEFAULT);
        if (color.getColor() == colorDefault.getColor()) {
            return closing + what;
        }
        const std::string opening = "\033[1;" + color.getColorString() + "m";
        return opening + what + closing;
    }

    static Color getColor(int value) {

        return Color(value);
    }
}

#endif
