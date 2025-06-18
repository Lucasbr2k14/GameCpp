#include "GameEngine/game.hpp"

int main(int argc, char **args) {

    Game *game = new Game(1280, 720, "Meu Joguinho");

    delete game;

    return 0;
}