#include "Adventure/Game.hh"
#include "Adventure/Map.hh"

#include "Interfaces/Console.hh"

int main(){
    Adventure::Game game;

    // Display greeting
    game.greet();

    // Start game
    game.start();

    return 0;
}
