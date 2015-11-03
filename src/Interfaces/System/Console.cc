#include "Console.hh"

namespace Interfaces{
namespace System{
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

    void Console::clear(){
        // Fill height with newlines
        for(size_t i = 0; i < this->height(); ++i)
            this->print("\n");
    }

    void Console::halt(){
        // Wait for enter to be pressed
        char c = this->getc();
        while(c != '\n')
            c = this->getc();
    }

    void Console::print(std::string format, ...){
        va_list list;

        // Get a list of all arguments, excluging 'format'
        va_start(list, format);

        // Print with arguments
        vfprintf(stdout, format.c_str(), list);

        // Close list
        va_end(list);
    }

    void Console::println(std::string format, ...){
        va_list list;

        // Get a list of all arguments, excluging 'format'
        va_start(list, format);

        // Print with arguments
        vfprintf(stdout, (format + '\n').c_str(), list);

        // Close list
        va_end(list);
    }

    std::string Console::gets(){
        // Read string from STDIN
        std::string s;
        std::cin >> s;

        return s;
    }

    char Console::getc(){
        // Read a character from STDIN
        return getchar();
    }
} // System
} // Interfaces
