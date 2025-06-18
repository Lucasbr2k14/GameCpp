#ifndef GAME_HPP
#define GAME_HPP

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <cmath>

#include "vector.hpp"
#include "player.hpp"
#include "sprite.hpp"

class Game {

    public:
        bool runing = true;
        int heigth;
        int width;

        Player *player;
        
        std::string game_name;

        SDL_Window *window;
        SDL_Renderer *render;

        Game(int h, int w, std::string game_name);        
        
    private:
        const int frame_rate = 60; // FPS
        const int frame_delay = 1000 / frame_rate;
        Uint32 frame_start;
        int frame_time;

        bool initSDL();
        bool createWindow();
        void createRender();
        void updateRenderer();
        void update();
        void keyBoard();
        void events();
        void loop();
        void draw();
        void exit();
};


#endif /*Game_HPP*/