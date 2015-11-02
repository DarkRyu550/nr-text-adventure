#include "AdventureCommon.hh"

namespace Adventure{
    /** Creates a Link from a JSON object. */
    Link::Link(const std::string& id, const Json::Value& json_link){
        // Fill link data
        this->id = id;
        for(std::string key : json_link.getMemberNames()){
            Json::Value child = json_link[key];

            if(key == LINK_NAME)
                // Child is the name
                this->name = child.asString();
            else if(key == LINK_ROOM_ID)
                // Child is the destination
                this->destination = child.asString();
            else if(key == LINK_TYPE){
                std::string type = child.asString();

                // Add the specified type if valid, if not, use "room"
                this->type = type.empty() ||
                            !(type == LINK_TYPE_ROOM || type == LINK_TYPE_EVENT) ?
                                LINK_TYPE_ROOM : type;
            }else if(key == LINK_MESSAGES){
                // Child contains the link's usage messages
                if(child.isArray() || child.isObject()){
                    for(Json::Value message : child){
                        // Add the string
                        this->messages.push_back(message.asString());
                    }
                }
            }
        }

        // If there is no current defined type, use "room"
        if(this->type.empty())
            this->type = LINK_TYPE_ROOM;
    }
}
