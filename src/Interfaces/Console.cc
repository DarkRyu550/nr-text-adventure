#include "Console.hh"

namespace Interfaces{
    Console::Console(){

    }

    Console::~Console(){

    }

    size_t Console::width() const{
        return 0;
    }

    size_t Console::height() const{
        return 200; // Symbolic height.
    }

    void Console::clear() const{
        // Fill height with newlines
        for(size_t i = 0; i < this->height(); ++i)
            this->print("\n");
    }

    void Console::halt() const{
        // Wait for any character to be pressed
        this->getc();
    }

    void Console::print(std::string format, ...) const{
        va_list list;

        // Get a list of all arguments, excluging 'format'
        va_start(list, format);

        // Print with arguments
        vfprintf(stdout, format.c_str(), list);

        // Close list
        va_end(list);
    }

    void Console::println(std::string format, ...) const{
        va_list list;

        // Get a list of all arguments, excluging 'format'
        va_start(list, format);

        // Print with arguments
        vfprintf(stdout, (format + '\n').c_str(), list);

        // Close list
        va_end(list);
    }

    std::string Console::gets() const{
        // Read string from STDIN
        std::string s;
        std::cin >> s;

        return s;
    }

    char Console::getc() const{
        // Read a character from STDIN
        fgetc(stdin);
    }
} // Interfaces
