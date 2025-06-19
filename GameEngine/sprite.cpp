#include "game.hpp"

Sprite::Sprite(int w, int h, float x, float y, float s, SDL_Renderer *game_render): position(x,y), velocity(0,0){
    this->speed = s;

    this->width = w;
    this->heigth = h;
    
    this->game_render = game_render;
    
    this->create_texture();
}

void Sprite::create_texture() {
    
}
