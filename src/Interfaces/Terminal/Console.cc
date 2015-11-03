#include "Console.hh"

namespace Interfaces{
namespace Terminal{
    void Console::initialize(int argc, char **argv){
        // Create a new GTK application
        _application =
            Gtk::Application::create(argc, argv, GTK_NAME);
    }

    Console::Console(){
        // Start the application
        _application->run(_window);
    }

    Console::~Console(){
        // Quit the currently running application
        _application->quit();
    }

    /** Clears the console. (Similar to "cls" or "clear") */
    void Console::clear(){
        // Clear the terminal's text buffer
        _window.console().get_buffer()->set_text("");
    }

    /** Waits for enter to be pressed. */
    void Console::halt(){
        char c = this->getc();
        while(c != '\n')
            c = this->getc();
    }

    /** Writes onto the console with formatting. */
    void Console::print(std::string format, ...){
        va_list list;

        // Get a list of all arguments, excluging 'format'
        va_start(list, format);

        // Store the format from printf in a buffer
        int length = vsnprintf(nullptr, 0, format.c_str(), list);
        std::vector<char> buffer(length + 1);
        vsnprintf(&buffer[0], buffer.size(), format.c_str(), list);

        // Save the buffer to a string and print it
        std::string string(buffer.begin(), buffer.end());

        Glib::ustring us = string;
        _window.console().get_buffer()->insert_at_cursor(us);

        // Close list
        va_end(list);
    }

    /** Same as print(), but with a newline. */
    void Console::println(std::string format, ...){
        va_list list;

        // Get a list of all arguments, excluging 'format'
        va_start(list, format);

        // Store the format from printf in a buffer
        int length = vsnprintf(nullptr, 0, format.c_str(), list);
        std::vector<char> buffer(length + 1);
        vsnprintf(&buffer[0], buffer.size(), format.c_str(), list);

        // Save the buffer to a string, add a newline and print it
        std::string string(buffer.begin(), buffer.end());
        string += '\n';

        Glib::ustring us = string;
        _window.console().get_buffer()->insert_at_cursor(us);

        // Close list
        va_end(list);
    }

    /** @return A line read from the console. */
    std::string Console::gets(){

    }

    /** @return A character read from the console. */
    char Console::getc(){

    }

    /** @return The width of the terminal, in character count. */
    size_t Console::width() const{
        return _window.get_width();
    }

    /** @return The height of the terminal, in carachter count. */
    size_t Console::height() const{
        return _window.get_height();
    }
} // Terminal
} // Interfaces
