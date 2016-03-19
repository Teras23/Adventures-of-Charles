#include <SDL_net.h>
#include <iostream>
#include "Client\Client.h"
#include "Server\Server.h"

int main(int argc, char* argv[]) {
    for(int i = 0; i < argc; i++) {
        std::cout << argv[i];
    }

    if(Client::Init() == 0) {
        Client::GameLoop();
    }
    SDLNet_Init();
    
    return 0;
}