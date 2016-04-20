#include <iostream>
#include "Client/Game.h"
#include "Server/Server.h"

int main(int argc, char* argv[]) {

    Game::onlineMode = false;

    for(int i = 1; i < argc; i++) {
        std::string argument = argv[i];
        Console::Print(argv[i]);

        if(argument.compare("-online") == 0) {
            if(i + 1 < argc) {
                Game::onlineMode = true;
                Game::serverIp = argv[i + 1];
                Console::Print(argv[i + 1]);
                i++;
            }
        }
    }
    
#if CLIENT
    Console::Print("Running Client!");
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