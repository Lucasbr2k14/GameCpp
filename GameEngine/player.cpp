#include "game.hpp"

Player::Player(float x, float y, SDL_Renderer *render): position(x,y), velocity(0,0){

    speed = 1;

    this->gameRender = render;

    this->createTexture();
};

Player::~Player() { }

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
};

void Player::walk(Direction dir) {

    switch (dir) {
        case Up:    this->velocity.y -= 1; break;
        case Down:  this->velocity.y += 1; break;
        case Left:  this->velocity.x -= 1; break;
        case Right: this->velocity.x += 1; break;
    }

};

void Player::update() {
    
    velocity = this->velocity.unitVector() * this->speed;
    this->position += velocity;

    dest.x = this->position.x;
    dest.y = this->position.y;
    dest.w = 120;
    dest.h = 120;
    
    this->velocity.reset();
    
};

void Player::draw() {

    SDL_RenderCopy(
        this->gameRender, 
        this->player_text,
        NULL,
        &dest
    );

};
