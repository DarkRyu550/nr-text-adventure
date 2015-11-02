#include "TerminalConsole.hh"

namespace Interfaces{
    TerminalConsole(TerminalWindow& window) : _window = window{

    }

    ~TerminalConsole(){

    }

    /** Clears the console. (Similar to "cls" or "clear") */
    void clear() const{
        // Clear the terminal's text buffer
        _window.get_buffer().set_text("");
    }

    /** Waits for a keypress. */
    void halt() const{

    }

    /** Writes onto the console with formatting. */
    void print(std::string, ...) const{

    }

    /** Same as print(), but with a newline. */
    void println(std::string = "", ...) const{

    }

    /** @return A line read from the console. */
    std::string gets() const{
        
    }

    /** @return A character read from the console. */
    char getc() const{

    }

    /** @return The width of the terminal, in character count. */
    size_t width() const{

    }

    /** @return The height of the terminal, in carachter count. */
    size_t height() const{

    }
} // Interfaces
