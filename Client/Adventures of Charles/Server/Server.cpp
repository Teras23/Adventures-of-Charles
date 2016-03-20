#include "Server.h"
#include <iostream>

int Server::clientid;

int Server::Init() {
    if(SDLNet_Init() < 0) {
        std::cout << "Could not init SDL_net " << SDLNet_GetError() << std::endl;
        return -1;
    }
    std::cout << "Server initialized" << std::endl;
    return 0;
}

void Server::Start() {
    
}