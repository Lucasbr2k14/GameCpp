#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "types.hpp"

class Player {

    SDL_Texture *playerText;
    SDL_Surface *tmp_surface;

    float x,y;
    float speed;

public:
    void draw();
    Player(float x, float y);
    void walk(Direction dir);
};

#endif /*PLAYER_HPP*/