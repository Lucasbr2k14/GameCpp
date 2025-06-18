#include "GameEngine/game.hpp"

int main() {

    Game *game = new Game(1280, 720, "Meu Joguinho");

    delete game;

    return 0;
}