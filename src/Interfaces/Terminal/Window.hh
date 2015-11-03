#ifndef TERMINAL_WINDOW_H_
#define TERMINAL_WINDOW_H_

#include "GtkCommon.hh"

namespace Interfaces{
namespace Terminal{
    class Window : public Gtk::Window{
    protected:
        /** The grid layout to contain objects. */
        Gtk::Grid _grid;

        /** Text view for displaying console output. */
        Gtk::TextView _console;

        /** Text entry for reading console input. */
        Gtk::Entry _prompt;

    public:
        Window();
        ~Window();

        Gtk::TextView& console();
        Gtk::Entry& prompt();
    };
} // Terminal
} // Interfaces

#endif // TERMINAL_WINDOW_H_
