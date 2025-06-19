#ifndef SPRITE_HPP
#define SPRITE_HPP

#include "game.hpp"

class Sprite {
    
    public:

        Sprite(int w, int h, float x, float y, float s, SDL_Renderer *game_render);
        ~Sprite();

    private:

        Vec2d position;
        Vec2d velocity;
        
        float speed;
        int heigth, width;

        SDL_Texture *sprite_text;
        SDL_Surface *tmp_surface;
        SDL_Renderer *game_render;

        SDL_Rect dest;

        void create_texture();


};

#endif 