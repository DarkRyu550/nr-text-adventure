#ifndef ADVENTURE_GAME_H_
#define ADVENTURE_GAME_H_

#include "../Interfaces/Console.hh" // Console input and output
#include "Map.hh"                   // Map system

namespace Adventure{
    class Game{
    public:
        /** Describes an in-game time point. */
        struct Time{
            u8 day;

            u8 hours;
            u8 minutes;
        };
    private:
        /** Console for text IO. */
        Interfaces::Console _console;

        /** Set this to true to stop the main loop */
        bool _quit = false;

        /** The game's maps */
        Map _map;

        /** The current room. */
        const Map::Room *_current_room = nullptr;

        /** A counter for link navigation in the current room. */
        struct{
            std::string link;
            size_t index;
        } _link_counter = {};

        /** The current time. */
        Time _time = {0};
    public:
        Game();
        ~Game();

        /** Starts the game. */
        void start();

        /** Quits the game. */
        void quit();
        
        /** Prompts the user to insert a command. */
        void prompt();

        /** Sets the current game time. */
        void set_time(const Time&);

        /** Enters the room with specified ID, null if none found. */
        void enter_room(const std::string&);

        /** Executes a game command */
        void execute(const std::string&);

        /** Writes game data onto the screen. */
        void display() const;

        /** Greets players with the welcome message. */
        void greet() const;

        /** @return The console currently being used by the game. */
        Interfaces::Console const& console() const;

        /** @return The game's greeting string. */
        std::string greeting() const;

        /** @return The game's current time. */
        Time const& time() const;
    };
}

#endif // ADVENTURE_GAME_H_
