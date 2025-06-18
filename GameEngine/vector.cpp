#include "game.hpp"

Vec2d::Vec2d(float x1, float y1){
    x = x1;
    y = y1;
};

float Vec2d::size() {
    return std::sqrt(x * x + y * y);
}

Vec2d Vec2d::unitVector() {
    
    float size = this->size();
    
    Vec2d new_vec = Vec2d(0,0);
    
    if (size != 0) {
        new_vec.x = this->x / size;
        new_vec.y = this->y / size;
        return new_vec;
    }

    return new_vec;
}

Vec2d Vec2d::operator+(const Vec2d *vec) {
    return Vec2d(this->x + vec->x, this->y + vec->y);
}

Vec2d Vec2d::operator+(const float scalar) {
    return Vec2d(this->x + scalar, this->y + scalar);
}

Vec2d Vec2d::operator*(const float scalar) {
    return Vec2d(this->x * scalar, this->y * scalar);
}

void Vec2d::operator*=(const float scalar) {
    this->x *= scalar, this->y *= scalar;
} 

void Vec2d::operator+=(const Vec2d vec) {
    this->x += vec.x, this->y += vec.y;
}

void Vec2d::reset() {
    x = 0, y = 0;
};

std::string Vec2d::show() {
    std::string s = "Vec2d(" + std::to_string(x) + ", " + std::to_string(y) + ")";
    return s;
}