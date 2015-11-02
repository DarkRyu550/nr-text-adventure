#include "Event.hh"

namespace Adventure{
    EventSet::EventSet(){

    }

    EventSet::~EventSet(){
        // Clear data
        this->clear();
    }

    void EventSet::append(const EventSet& set, bool overwrite){
        // Iterate through the set's events
        for(auto it = set.events().begin(); it != set.events().end(); ++it){
            Event event = it->second;

            // Check if the set currently has an event in the same ID
            if(this->_events.find(event.id) != _events.end()){
                // Found, check if overwriting is enabled and write it if so
                if(overwrite)
                    this->_events[event.id] = event;
            }else{
                // Not found, just add it
                this->_events[event.id] = event;
            }
        }
    }

    void EventSet::load(Json::Value root){
        // Iterate through all children
        for(std::string id : root.getMemberNames()){
            Json::Value json_event = root[id];

            // Ignore all non-object values
            if(json_event.type() != Json::objectValue)
                continue;

            // Create a new Event
            Event event;
            event.id = id;

            // Iterate through the event's children
            for(std::string key : json_event.getMemberNames()){
                Json::Value child = json_event[key];

                // Check for variables
                if(key == EVENT_QUIT){
                    event.quit = Link(key, child);
                }else if(key == EVENT_MESSAGES){
                    // Child contains the event's messages
                    if(child.isArray() || child.isObject()){
                        for(Json::Value message : child){
                            // Add the string
                            event.messages.push_back(message.asString());
                        }
                    }
                }
            }

            // Add the event to the map
            _events[event.id] = event;
        }
    }

    void EventSet::load(std::string json){
        Json::Value root;

        // Parse string onto root
        Json::Reader reader;
        if(!reader.parse(json, root))
            throw std::runtime_error("An error ocurred during parsing of the JSON event set:\n\t" + reader.getFormattedErrorMessages());

        // Continue processing
        this->load(root);
    }

    void EventSet::load(std::istream& stream){
        Json::Value root;

        // Read input stream onto root
        Json::Reader reader;
        if(!reader.parse(stream, root))
            throw std::runtime_error("An error ocurred during parsing of the JSON event set:\n\t" + reader.getFormattedErrorMessages());

        // Continue processing
        this->load(root);
    }

    void EventSet::clear(){
        // Clear the map
        _events.clear();
    }

    std::unordered_map<std::string, Event> const& EventSet::events() const{
        return this->_events;
    }
}
