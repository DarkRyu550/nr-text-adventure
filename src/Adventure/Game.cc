#include "Game.hh"

namespace Adventure{
    Game::Game(){
        // Clear and load maps
        _map.clear();

        std::ifstream map_nr("Assets/NR.json");
        _map.load(map_nr);

        // Clear and load events
        _events.clear();

        std::ifstream event_file("Assets/Events.json");
        _events.load(event_file);
    }

    Game::~Game(){

    }

    void Game::start(){
        // Set starting time
        Game::Time start;
        start.day     = 1;
        start.hours   = 17;
        start.minutes = 30;

        set_time(start);

        // Create a link to the start room and enter it
        Link start_room;
        start_room.type = LINK_TYPE_ROOM;
        start_room.destination = "início";

        this->enter_link(start_room);

        // Main prompt loop
        this->_quit = false;
        while(!_quit){
            this->prompt();
        }
    }

    void Game::quit(){
        // TODO: Display exit mesage
        this->_console.halt();

        // Set quit to true
        this->_quit = true;
    }

    void Game::prompt(){
        // Write prompt
        _console.print("> ");

        // Wait for a line of input
        std::string command = _console.gets();

        // Execute command
        this->execute(command);
    }

    void Game::set_time(const Game::Time& time){
        // Update the time variable
        this->_time = time;

        // TODO: Notify events
    }

    void Game::enter_link(const Link& link){
        // Check for available rooms with the given ID
        if(link.type == LINK_TYPE_ROOM){
            auto it = _map.rooms().find(link.destination);
            if(it != _map.rooms().end())
                this->_current_room = &(it->second);
            else
                this->_current_room = nullptr;

            // Clear link counter
            this->_link_counter = {};

            // Display changes
            this->display();
        }else if(link.type == LINK_TYPE_EVENT){
            auto it = _events.events().find(link.destination);
            if(it == _events.events().end()){
                _console.println("Erro: link para evento inexistente. (Game.cc, linha 80)\n"
                                    "\tEm link de ID \"%s\"\n"
                                    "\tGame::_events::find(\"%s\") retornou Iterator::end()\n"
                                    "\tGame::_current_room::id = \"%s\"\n"
                                    "\tGame::_time = {%d, %d, %d}\n",
                                        link.id.c_str(), link.destination.c_str(),
                                        _current_room ? _current_room->id.c_str() : "nullptr",
                                        _time.day, _time.hours, _time.minutes);

                // Quit function
                return;
            }

            // Get the event
            Event event = it->second;

            // Clear console
            _console.clear();
            _console.halt(); // Bodge, prevent double messages

            // Iterate through its messages
            for(size_t i = 0; i < event.messages.size(); ++i){
                _console.println(event.messages[i].c_str());
                _console.halt();
            }

            // Enter the quit link
            this->enter_link(event.quit);
        }else{
            // Display an error
            _console.println("Error: Tried to enter link with invalid type.\n"
                                "\tLink::id = \"%s\"\n"
                                "\tLink::type = \"%s\"\n"
                                "\tLink::destination = \"%s\"",
                            link.id.c_str(), link.type.c_str(), link.destination.c_str());
        }
    }

    void Game::execute(const std::string& command){
        // Define a macro for direction counting
        #define DISPLAY_USAGE_MESSAGE(ID, LINK) \
            if(this->_link_counter.link != ID){ \
                this->_link_counter.link = ID; \
                this->_link_counter.index = 0; \
                \
                if(!LINK.messages.empty()){\
                    std::string message = LINK.messages[this->_link_counter.index]; \
                    if(!message.empty()) \
                        this->_console.println(message); \
                    \
                    if(this->_link_counter.index < LINK.messages.size() - 1) \
                        ++this->_link_counter.index; \
                }\
            }else{ \
                if(!LINK.messages.empty()){\
                    std::string message = LINK.messages[this->_link_counter.index]; \
                    if(!message.empty()) \
                        this->_console.println(message); \
                    \
                    if(this->_link_counter.index < LINK.messages.size() - 1) \
                        ++this->_link_counter.index; \
                }\
            }

        // Define a macro for entering a room if available
        #define ENTER_AVAILABLE_ROOM(ID) \
            auto it = _current_room->links.find(ID); \
            if(it != _current_room->links.end()){ \
                if(!it->second.destination.empty()){ \
                    this->enter_link(it->second); \
                    DISPLAY_USAGE_MESSAGE(ID, it->second); \
                }else{ \
                    this->_console.println("Você não pode ir nessa direção."); \
                    DISPLAY_USAGE_MESSAGE(ID, it->second); \
                }\
            }else \
                this->_console.println("Você não pode ir nessa direção.");

        if(command == "olhar"){
            // Clear screen and display.
            this->display();
        }else if(command == "sair" || command == "quit" || command == "exit"){
            // Exit the game
            this->quit();
        }else if(command == "norte"){
            // Enter room to the north, if available
            ENTER_AVAILABLE_ROOM(DIRECTION_NORTH);
        }else if(command == "sul"){
            // Enter room to the south, if available
            ENTER_AVAILABLE_ROOM(DIRECTION_SOUTH);
        }else if(command == "oeste"){
            // Enter room to the west, if available
            ENTER_AVAILABLE_ROOM(DIRECTION_WEST);
        }else if(command == "leste"){
            // Enter room to the east, if available
            ENTER_AVAILABLE_ROOM(DIRECTION_EAST);
        }else if(command == "noroeste"){
            // Enter room to the north-west, if available
            ENTER_AVAILABLE_ROOM(DIRECTION_NORTHWEST);
        }else if(command == "nordeste"){
            // Enter room to the north-east, if available
            ENTER_AVAILABLE_ROOM(DIRECTION_NORTHEAST);
        }else if(command == "sudoeste"){
            // Enter room to the south-west, if available
            ENTER_AVAILABLE_ROOM(DIRECTION_SOUTHWEST);
        }else if(command == "sudeste"){
            // Enter room to the south-east, if available
            ENTER_AVAILABLE_ROOM(DIRECTION_SOUTHEAST);
        }else{
            // Dispklay an error message
            this->_console.println("O comando \"%s\" não é valido.", command.c_str());
        }

        // Undefine macros
        #undef ENTER_AVAILABLE_ROOM
        #undef DISPLAY_USAGE_MESSAGE
    }

    void Game::display() const{
        // Clear the screen
        _console.clear();

        if(!_current_room){
            // Describe the "World End" room
            _console.print("Erro fatal: Ponteiro nulo.\n\n");

            _console.print("Você está no... Fim do mundo, eu acho.\n\n");

            _console.print("Para todos que não conhecem o NR ainda, isso não ");
            _console.print("um lugar real, e sim um problema com o jogo. ");
            _console.print("Mas vou descrever esse lugar assim mesmo...\n\n");

            _console.print("Um lugar escuro e que parece abandonado, mas, ");
            _console.print("na verdade é o lar de várias criaturas perdidas ");
            _console.print("no tempo, como o Roberto Carlos, Bill & Ted, ");
            _console.print("aqueles limões da Pepsi, ");
            _console.print("o clipe de papel do Office, o Acre e a Simone ");
            _console.print("cantando \"Então é Natal\" por toda a eternidade.\n");

            _console.print("Mas não se engane, este não é o inferno.\n\n");

            _console.print("Aperte qualquer tecla para sair do jogo.");
            _console.halt();
            _console.println();

            // Exit game
            exit(1);
        }

        // Write current location
        _console.print("Você está %s.\n\n", _current_room->name.c_str());

        // Write time
        _console.print(
              std::to_string(_time.day) + "º dia, às "
            + std::to_string(_time.hours)
            + ':' + std::to_string(_time.minutes)
            + "\n\n");

        // Write links
        // Firstly, define a macro
        #define PRINT_LINK(ID, NAME) \
            { \
                auto it = _current_room->links.find(ID); \
                if(it != _current_room->links.end()) \
                _console.println("Ao %s há %s.", NAME, it->second.name.c_str()); \
            }

        // Now, use that macro to repeat the code
        PRINT_LINK(DIRECTION_NORTH,     "norte");
        PRINT_LINK(DIRECTION_SOUTH,     "sul");
        PRINT_LINK(DIRECTION_EAST,      "leste");
        PRINT_LINK(DIRECTION_WEST,      "oeste");
        PRINT_LINK(DIRECTION_NORTHEAST, "nordeste");
        PRINT_LINK(DIRECTION_NORTHWEST, "noroeste");
        PRINT_LINK(DIRECTION_SOUTHEAST, "sudeste");
        PRINT_LINK(DIRECTION_SOUTHWEST, "sudoeste");

        #undef PRINT_LINK
        _console.println();
    }

    std::string Game::greeting() const{
        std::string greeting =
            std::string("Seja bem-vindo ao meu diário de bordo do NR!\n") +
            "\n" +
            "Acho que você já pôde notar que este diário não está em um formato nada convencional, " +
            "sim, este é um jogo text adventure, como os antigos de MS-DOS e Windows 95. (Levante a mão se se lembra deles) \n" +
            "\n" +
            "Mas antes de continuar, tenha certeza que está jogando em um terminal com suporte a UTF-8 para que os acentos e o til " +
            "funcionem direito, e não fiquem parecendo um monte de letras aleatórias, como, por exemplo: \"Ã©\".\n" +
            "\n" +
            "Se isso estiver acontecendo, use um terminal que tenha suporte (Exemplos: Gnome Terminal, no Linux. Cygwin, no Windows).\n" +
            "\n";

        return greeting;
    }

    void Game::greet() const{
        // Clear screen
        _console.clear();

        // Write the greeting onto the screen
        _console.print("%s", this->greeting().c_str());

        // Pause
        _console.print("Aperte qualquer tecla para começar.");
        _console.halt();

        _console.println();
    }

    Interfaces::DefaultConsole const& Game::console() const{
        return this->_console;
    }

    Game::Time const& Game::time() const{
        return this->_time;
    }
} // Adventure
