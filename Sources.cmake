# Add sources for the NrAdventure project
set(Adventure_SOURCES

    src/Interfaces/System/Console.cc

    src/Adventure/AdventureCommon.cc
    src/Adventure/Event.cc
    src/Adventure/Map.cc
    src/Adventure/Game.cc

    src/Main.cc
)

# Set system console variables
set(Adventure_SYS_CONSOLE_CLASS Interfaces::System::Console)
set(Adventure_SYS_CONSOLE_FILE  src/Interfaces/System/Console.hh)
