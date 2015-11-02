# Add sources for the NrAdventure project
set(Adventure_SOURCES

    src/Main.cc

    src/Interfaces/Console.cc

    src/Adventure/Game.cc
    src/Adventure/Map.cc
    src/Adventure/Event.cc
    src/Adventure/AdventureCommon.cc
)

# Set system console variables
set(Adventure_SYS_CONSOLE_CLASS Console)
set(Adventure_SYS_CONSOLE_FILE  src/Interfaces/Console.hh)
