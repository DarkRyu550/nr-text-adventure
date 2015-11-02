#ifndef ADVENTURE_MAP_H_
#define ADVENTURE_MAP_H_

#include "AdventureCommon.hh"

// Room's variable names
#define ROOM_DISPLAY_NAME "location"

// Map directions
#define DIRECTION_NORTH "north"
#define DIRECTION_SOUTH "south"
#define DIRECTION_EAST  "east"
#define DIRECTION_WEST  "west"

#define DIRECTION_NORTHEAST "north-east"
#define DIRECTION_NORTHWEST "north-west"

#define DIRECTION_SOUTHEAST "south-east"
#define DIRECTION_SOUTHWEST "south-west"

namespace Adventure{
    class Map{
    public:
        struct Room{
            /** The room's ID. */
            std::string id;

            /** The room's display name. */
            std::string name;

            /** All the room's links. */
            std::unordered_map<std::string, Link> links;
        };

    protected:
        /** All rooms loaded in this current map. */
        std::unordered_map<std::string, Room> _rooms;

    public:
        Map();
        ~Map();

        /**
         * Appends another map to this one.
         *
         * @param Map& - The map to be added.
         * @param bool - Enables or disables value overwriting.
         */
        void append(const Map&, bool = false);

        /** Loads and appends a JSON map into the current map data. */
        void load(Json::Value);

        /**
         * Loads and appends a JSON map into the current map data.
         *
         * @param std::string - The JSON data.
         */
        void load(std::string);

        /**
         * Loads and appends a JSON map into the current map data.
         *
         * @param std::istream& - Reads JSON data from the input stream.
         */
        void load(std::istream&);

        /** Clears all map data. */
        void clear();

        /** @return The list of rooms currently loaded to the map. */
        std::unordered_map<std::string, Room> const& rooms() const;
    };
}

#endif // ADVENTURE_MAP_H_
