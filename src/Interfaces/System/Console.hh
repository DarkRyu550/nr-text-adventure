#ifndef CONSOLE_H_
#define CONSOLE_H_

#include "Common.hh"

namespace Interfaces{
namespace System{
    class Console{
    public:
        Console();
        ~Console();

        /** Initializes the Console. */
        static void initialize(int, char**) { }

        /** Clears the Console. (Similar to "cls" or "clear") */
        void clear();

        /** Waits for a keypress. */
        void halt();

        /** Writes onto the Console with formatting. */
        void print(std::string, ...);

        /** Same as print(), but with a newline. */
        void println(std::string = "", ...);

        /** @return A line read from the Console. */
        std::string gets();

        /** @return A character read from the Console. */
        char getc();

        /** @return The width of the terminal, in character count. */
        size_t width() const;

        /** @return The height of the terminal, in carachter count. */
        size_t height() const;
    }; // Console
} // System
} // Interfaces

#endif // CONSOLE_H_
