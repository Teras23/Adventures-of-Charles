#include <iostream>
#include "Client/Game.h"
#include "Server/Server.h"

int main(int argc, char* argv[]) {

    for(int i = 1; i < argc; i++) {
        std::cout << argv[i] << std::endl;
    }
    
#if CLIENT
    Console::Print("Running Client!");
    Game::onlineMode = false;
    if(Game::Init() == 0) {
        Game::Loop();
    }
#elif SERVER
    Console::Print("Running Server!");
    if(Server::Init() == 0) {
        Server::Loop();
    }
#endif
    return 0;
}