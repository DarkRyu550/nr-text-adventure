#ifndef ADVENTURE_EVENT_H_
#define ADVENTURE_EVENT_H_

#include "AdventureCommon.hh"

// The message's variables
#define EVENT_QUIT     "quit"
#define EVENT_MESSAGES "messages"

namespace Adventure{
    class EventSet{
    public:
        /** The set's events. */
        std::unordered_map<std::string, Event> _events;
    public:
        EventSet();
        ~EventSet();

        /**
         * Appends another event set to this one.
         *
         * @param EventSet& - The map to be added.
         * @param bool - Enables or disables value overwriting.
         */
        void append(const EventSet&, bool = false);

        /** Loads and appends a JSON event set into the current map data. */
        void load(Json::Value);

        /**
         * Loads and appends a JSON event set into the current map data.
         *
         * @param std::string - The JSON data.
         */
        void load(std::string);

        /**
         * Loads and appends a JSON event set into the current map data.
         *
         * @param std::istream& - Reads JSON data from the input stream.
         */
        void load(std::istream&);

        /** Clears all events. */
        void clear();

        /** @return The list of events currently loaded to the set. */
        std::unordered_map<std::string, Event> const& events() const;
    };
}

#endif // ADVENTURE_EVENT_H_
