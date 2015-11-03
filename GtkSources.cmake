# Append GTK sources
list(INSERT Adventure_SOURCES START
    src/Interfaces/Terminal/Window.cc
    src/Interfaces/Terminal/Console.cc
)

# Set the GTK console class and file
set(Adventure_GTK_CONSOLE_CLASS Terminal::Console)
set(Adventure_GTK_CONSOLE_FILE  src/Interfaces/Terminal/Console.hh)
