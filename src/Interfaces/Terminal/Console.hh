#ifndef CONSOLE_H_
#define CONSOLE_H_

#include "GtkCommon.hh"
#include "Window.hh"

namespace Interfaces{
namespace Terminal{
    class Console{
    protected:
        /** The terminal's application. */
        static Glib::RefPtr<Gtk::Application> _application;

        /** The terminal window. */
        Window _window;

        /** Workaround for lambda bug, runs the GTK application in another thread. */
        void start_thread();
    public:
        Console();
        ~Console();

        /** Initializes the Console. */
        static void initialize(int, char**);

        /** Clears the console. (Similar to "cls" or "clear") */
        void clear();

        /** Waits for a keypress. */
        void halt();

        /** Writes onto the console with formatting. */
        void print(std::string, ...);

        /** Same as print(), but with a newline. */
        void println(std::string = "", ...);

        /** @return A line read from the console. */
        std::string gets();

        /** @return A character read from the console. */
        char getc();

        /** @return The width of the terminal, in character count. */
        size_t width() const;

        /** @return The height of the terminal, in carachter count. */
        size_t height() const;
    };
} // Terminal
} // Console

#endif // CONSOLE_H_
