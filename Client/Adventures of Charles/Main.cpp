#include <iostream>
#include "Game.h"
#include "Server.h"

int main(int argc, char* argv[]) {

    for(int i = 1; i < argc; i++) {
        std::cout << argv[i] << std::endl;
    }
    
#if CLIENT
    Game::onlineMode = false;
    if(Game::Init() == 0) {
        Game::Loop();
    }
#elif SERVER
    if(Server::Init() == 0) {
        Server::Loop();
    }
#endif
    return 0;
}