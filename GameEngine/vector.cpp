#include "game.hpp"

Vec2d::Vec2d(float x1 =0.0f, float y1=0.0f){
    x = x1;
    y = y1;
};

float Vec2d::size() {
    return std::sqrt(x * x + y * y);
}

Vec2d *Vec2d::unitVector() {
    Vec2d *new_vec = new Vec2d();

    float size = this->size();

    


    return new_vec;
}

std::string Vec2d::show() {
    std::string s = "Vec2d(" + std::to_string(x) + ", " + std::to_string(y) + ")";
    return s;
}