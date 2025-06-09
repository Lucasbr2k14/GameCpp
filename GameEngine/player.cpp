#include "game.hpp"

Player::Player(float x, float y, SDL_Renderer *render) {

    speed = 0.5;

    this->x = x;
    this->y = y;

    this->gameRender = render;

    this->createTexture();
}

void Player::createTexture() {
    this->tmp_surface = IMG_Load("Images/Ball.png");

    if (this->tmp_surface == nullptr) {
        std::cout << SDL_GetError() << std::endl;
        return;
    }

    this->player_text = SDL_CreateTextureFromSurface(
        this->gameRender, 
        tmp_surface
    );

    if (this->player_text == nullptr) {
        std::cout << SDL_GetError() << std::endl;
        SDL_FreeSurface(tmp_surface);
        return;
    }

}

void Player::walk(Direction dir) {
    switch (dir) {
        case Up: this->y -= this->speed; break;
        case Down: this->y += this->speed; break;
        case Left: this->x += this->speed; break;
        case Right: this->x -= this->speed; break;
    }
}

void Player::draw() {
    SDL_RenderCopy(
        this->gameRender, 
        this->player_text,
        NULL,
        NULL
    );
}
