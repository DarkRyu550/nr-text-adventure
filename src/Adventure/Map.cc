#include "Map.hh"

namespace Adventure{
    Map::Map(){
    }

    Map::~Map(){
        // Clear the map's data
        this->clear();
    }

    void Map::append(const Map& map, bool overwrite){
        // Iterate through all of the map's rooms
        for(auto it = map.rooms().begin(); it != map.rooms().end(); ++it){
            Map::Room room = it->second;

            // Check if the map currently has a room in the same ID
            if(this->_rooms.find(room.id) != _rooms.end()){
                // Found, check if overwriting is enabled and write it if so
                if(overwrite)
                    this->_rooms[room.id] = room;
            }else{
                // Not found, just add it
                this->_rooms[room.id] = room;
            }
        }
    }

    void Map::load(Json::Value root){
        // Iterate through all children
        for(std::string id : root.getMemberNames()){
            Json::Value json_room = root[id];

            // Ignore all non-object values
            if(json_room.type() != Json::objectValue)
                continue;

            // Create a new room
            Map::Room room;
            room.id = id;

            // Iterate through the the room's children
            for(std::string key : json_room.getMemberNames()){
                Json::Value child = json_room[key];

                // Check for defined variables and directions
                if(key == ROOM_DISPLAY_NAME){
                    room.name = child.asString();
                }else if(key == DIRECTION_NORTH){
                    // North
                    room.links[DIRECTION_NORTH] = Link(key, child);
                }else if(key == DIRECTION_SOUTH){
                    // South
                    room.links[DIRECTION_SOUTH] = Link(key, child);
                }else if(key == DIRECTION_EAST){
                    // East
                    room.links[DIRECTION_EAST] = Link(key, child);
                }else if(key == DIRECTION_WEST){
                    // West
                    room.links[DIRECTION_WEST] = Link(key, child);
                }else if(key == DIRECTION_NORTHWEST){
                    // North-west
                    room.links[DIRECTION_NORTHWEST] = Link(key, child);
                }else if(key == DIRECTION_NORTHEAST){
                    // North-east
                    room.links[DIRECTION_NORTHEAST] = Link(key, child);
                }else if(key == DIRECTION_SOUTHWEST){
                    // South-west
                    room.links[DIRECTION_SOUTHWEST] = Link(key, child);
                }else if(key == DIRECTION_SOUTHEAST){
                    // South-east
                    room.links[DIRECTION_SOUTHEAST] = Link(key, child);
                }

                // For now, ignore all other room variables
            }

            // Add the room to the rooms list
            this->_rooms[room.id] = room;
        }
    }

    void Map::load(std::string json){
        Json::Value root;

        // Parse string onto root
        Json::Reader reader;
        if(!reader.parse(json, root))
            throw std::runtime_error("An error ocurred during parsing of the JSON map:\n\t" + reader.getFormattedErrorMessages());

        // Continue processing
        this->load(root);
    }

    void Map::load(std::istream& stream){
        Json::Value root;

        // Read input stream onto root
        Json::Reader reader;
        if(!reader.parse(stream, root))
            throw std::runtime_error("An error ocurred during parsing of the JSON map:\n\t" + reader.getFormattedErrorMessages());

        // Continue processing
        this->load(root);
    }

    void Map::clear(){
        // Clear the room map
        this->_rooms.clear();
    }

    std::unordered_map<std::string, Map::Room> const& Map::rooms() const{
        return this->_rooms;
    }
} // Adventure
