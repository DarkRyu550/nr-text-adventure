#ifndef TERMINAL_WINDOW_H_
#define TERMINAL_WINDOW_H_

#include "GtkCommon.h"

namespace Interfaces{
    class TerminalWindow : public Gtk::Window{
    protected:
        /** The grid layout to contain objects. */
        Gtk::Grid _grid;

        /** Text view for displaying console output. */
        Gtk::TextView _console;

        /** Text entry for reading console input. */
        Gtk::Entry _prompt;

    public:
        TerminalWindow();
        ~TerminalWindow();

        Gtk::TextView const& console() const;

        Gtk::Entry const& prompt() const;
    };
}

#endif // TERMINAL_WINDOW_H_
