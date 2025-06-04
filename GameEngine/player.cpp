#include "game.hpp"

Player::Player(float x, float y) {

    speed = 0.5;

    this->x = x;
    this->y = y;
}

void Player::walk(Direction dir) {
    switch (dir) {
        case Up: this->y -= this->speed; break;
        case Down: this->y += this->speed; break;
        case Left: this->x += this->speed; break;
        case Right: this->x -= this->speed; break;
    }
}

void draw() {

}
