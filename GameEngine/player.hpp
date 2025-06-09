#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "types.hpp"

class Player {
private:
    SDL_Texture *player_text;
    SDL_Surface *tmp_surface;
    SDL_Renderer *gameRender;
    
public:
    float x,y;
    float speed;

    Player(float x, float y, SDL_Renderer *render);
    void draw();
    void createTexture();
    void walk(Direction dir);
};

#endif /*PLAYER_HPP*/