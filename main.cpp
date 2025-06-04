#include "GameEngine/game.hpp"

using namespace std;


// Create class game



// End class game

int main(int argc, char **args) {

    Game *game = new Game(1280, 720, "Meu Joguinho");

    delete game;

    return 0;
}