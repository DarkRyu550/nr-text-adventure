# Append GTK sources
list(APPEND Adventure_SOURCES

    src/Interfaces/Terminal/TerminalWindow.cc
)

# Set the GTK console class and file
set(Adventure_GTK_CONSOLE_CLASS TerminalConsole)
set(Adventure_GTK_CONSOLE_FILE  src/Interfaces/Terminal/TerminalConsole.hh)
