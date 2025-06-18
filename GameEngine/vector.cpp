#include "game.hpp"

Vec2d::Vec2d(float x1, float y1){
    x = x1;
    y = y1;
};

float Vec2d::size() {
    return std::sqrt(x * x + y * y);
}

Vec2d *Vec2d::unitVector() {
    Vec2d *new_vec = new Vec2d(0,0);

    float size = this->size();

    if (size == 0) {
        return new_vec;
    }

    new_vec->x = this->x / size;
    new_vec->y = this->y / size;

    return new_vec;
}

void Vec2d::reset() {
    x = 0, y = 0;
};

std::string Vec2d::show() {
    std::string s = "Vec2d(" + std::to_string(x) + ", " + std::to_string(y) + ")";
    return s;
}