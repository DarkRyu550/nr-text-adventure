#include "Adventure/Game.hh"
#include "Adventure/Map.hh"

int main(int argc, char **argv){
    Adventure::Game game;

    // Display greeting
    game.greet();

    // Start game
    game.start();

    return 0;
}
