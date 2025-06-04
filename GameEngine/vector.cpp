#include "game.hpp"

Vec2d::Vec2d(float x1, float y1){
    x = x1;
    y = y1;
};

float Vec2d::size() {
    return std::sqrt(x * x + y * y);
}

std::string Vec2d::show() {
    std::string s = "Vec2d(" + std::to_string(x) + ", " + std::to_string(y) + ")";
    return s;
}