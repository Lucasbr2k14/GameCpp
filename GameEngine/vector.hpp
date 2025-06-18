#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>

class Vec2d {

public:
    float x;
    float y;
    
    Vec2d(float x1, float y1);
    Vec2d normalize();
    Vec2d *unitVector();
    void reset();
    float size();
    float sin();
    float cos();
    float tg();
    float angle();
    std::string show();
};

#endif /*VECTOR_HPP*/