#include "Color.h"

Color::Color(int value) {

    color = value;
}

int Color::getColor() {

    return color;
}

std::string Color::getColorString() {

    return std::to_string(color);
}