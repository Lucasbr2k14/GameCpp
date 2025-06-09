#include "game.hpp"

using namespace std;

Game::Game(int h, int w, string game_name){
    this->heigth = h;
    this->width = w;
    this->game_name = game_name;

    
    this->initSDL();
    this->createWindow();
    this->createRender();

    this->player = new Player(0,0, this->render);
    
    this->loop();
    this->exit();
};

bool Game::initSDL() {
    int init = SDL_Init(SDL_INIT_EVERYTHING);
    
    if (init < 0) {
        cout << "Error: SDL_Init " << SDL_GetError() << endl;
        return true;
    }
    
    return false;
}

bool Game::createWindow() {

    this->window = SDL_CreateWindow(
        this->game_name.c_str(),
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        this->heigth, this->width,
        SDL_WINDOW_SHOWN
    );

    if (this->window == NULL) {
        cout << "Error: SDL_init: " << SDL_GetError() << endl;
        return true;
    }

    return false;
};


void Game::createRender() {
    this->render = SDL_CreateRenderer(this->window, -1, 0);

    if (this->render == NULL) {
        cout << "Error: SDL_CreateRender: " << SDL_GetError() << endl;
        return;
    }

    SDL_SetRenderDrawColor(this->render, 0,0,0, 255);
};

void Game::updateRenderer() {
    SDL_RenderClear(this->render);
    this->draw();
    SDL_RenderPresent(this->render);
}

void Game::events() {

    SDL_Event event;

    while(SDL_PollEvent(&event)) {
        
        if (event.type == SDL_QUIT) {
            this->runing = false;
        }

    }
};

void Game::loop() {
    while(Game::runing) {

        frame_start = SDL_GetTicks();
        

        this->events();
        this->updateRenderer();

        frame_time = SDL_GetTicks() - frame_start;

    }
};

void Game::draw() {
    this->player->draw();
}

void Game::exit() {
    delete player;
    SDL_DestroyWindow(this->window);
    SDL_DestroyRenderer(this->render);
    SDL_Quit();
};
