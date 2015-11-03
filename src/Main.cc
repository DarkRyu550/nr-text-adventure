#include "Adventure/Game.hh"
#include "Adventure/Map.hh"

int main(int argc, char **argv){
    // Initialize Console
    Interfaces::Console::initialize(argc, argv);

    // Create a game instance
    Adventure::Game game(argc, argv);

    // Display greeting
    game.greet();

    // Start game
    game.start();

    return 0;
}
