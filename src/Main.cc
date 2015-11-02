#include "Adventure/Game.hh"
#include "Adventure/Map.hh"

#include "Interfaces/Console.hh"

#include "Interfaces/Terminal/TerminalWindow.hh"

int main(int argc, char **argv){
    Adventure::Game game;

    // Display greeting
    game.greet();

    // Start game
    game.start();

    Glib::RefPtr<Gtk::Application> app =
        Gtk::Application::create(argc, argv,
          "org.gtkmm.examples.base");


    Interfaces::TerminalWindow window;
    app->run(window);

    return 0;
}
