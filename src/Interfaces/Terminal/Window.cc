#include "Window.hh"

namespace Interfaces{
namespace Terminal{
    Window::Window(){
        // Set default Window properties
        this->set_title(DISPLAY_NAME);
        this->set_default_size(1280, 720);

        // Make the console dark and monospaced, then add it to the grid
        _console.override_background_color(Gdk::RGBA("#000"));
        _console.set_monospace(true);
        _console.set_editable(false);

        _console.property_expand() = true;

        _grid.attach(_console, 0, 0, 1, 1);

        // Make the prompt monospaced, then add it to the grid
        _prompt.set_placeholder_text("Digite um comando");
        _prompt.set_editable(true);
        _prompt.grab_focus();

        _grid.attach(_prompt, 0, 1, 1, 1);

        // Add grid
        this->add(_grid);
        // Show all widgets
        this->show_all_children();
    }

    Window::~Window(){

    }

    Gtk::TextView& Window::console(){
        return _console;
    }

    Gtk::Entry& Window::prompt(){
        return _prompt;
    }
} // Terminal
} // Interfaces
