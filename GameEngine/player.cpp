#include "game.hpp"

Player::Player(float x, float y, SDL_Renderer *render) {

    position = new Vec2d(x,y);
    velocity = new Vec2d(0,0);

    speed = 1;

    this->gameRender = render;

    this->createTexture();
};

Player::~Player() {
    delete position, velocity;
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

};

void Player::walk(Direction dir) {

    switch (dir) {
        case Up:    this->velocity->y -= 1; break;
        case Down:  this->velocity->y += 1; break;
        case Left:  this->velocity->x -= 1; break;
        case Right: this->velocity->x += 1; break;
    }

};

void Player::update() {
    
    Vec2d * unit_velocity = this->velocity->unitVector();
    
    this->position->x += unit_velocity->x * this->speed;
    this->position->y += unit_velocity->y * this->speed;

    dest.x = this->position->x;
    dest.y = this->position->y;
    dest.w = 32;
    dest.h = 32;
    
    velocity->reset();
    
    delete unit_velocity;
};

void Player::draw() {

    SDL_RenderCopy(
        this->gameRender, 
        this->player_text,
        NULL,
        &dest
    );

};
