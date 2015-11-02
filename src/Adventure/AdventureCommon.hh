#ifndef COMMON_ADVENTURE_H_
#define COMMON_ADVENTURE_H_

#include "../Common.h"

// Link's variable names
#define LINK_NAME     "name"
#define LINK_TYPE     "type"
#define LINK_ROOM_ID  "link"
#define LINK_MESSAGES "messages"

#define LINK_TYPE_ROOM  "room"
#define LINK_TYPE_EVENT "event"

namespace Adventure{
    struct Link{
        Link() { }
        Link(const std::string&, const Json::Value&);

        /** The link's ID. */
        std::string id = "";

        /** Display name for the link. */
        std::string name = "";

        /** Messages to display when the link is activated. */
        std::vector<std::string> messages;

        /** The links's destination type */
        std::string type = LINK_TYPE_ROOM;

        /** ID of the destination room. */
        std::string destination = "";
    };

    struct Event{
        /** The event's ID */
        std::string id = "";

        /** The event's messages */
        std::vector<std::string> messages;

        /** The event's quit link. */
        Link quit = { };
    };
}

#endif // COMMON_ADVENTURE_H_
