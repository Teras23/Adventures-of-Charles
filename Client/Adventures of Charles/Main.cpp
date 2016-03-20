#include <SDL_net.h>
#include <iostream>
#include "Client\Client.h"
#include "Server\Server.h"

int main(int argc, char* argv[]) {
    bool server = false;

    for(int i = 1; i < argc; i++) {
        std::cout << argv[i] << std::endl;
        if(strcmp(argv[i], "-s") == 0) {
            server = true;
        }
    }

    if(!server) {
        if(Client::Init() == 0) {
            Client::GameLoop();
        }
    }
    else {
        if(Server::Init() == 0) {
            Server::Start();
        }
    }
    
    return 0;
}