#include <SDL_net.h>
#include <iostream>
#include "Client.h"

int main(int argc, char* argv[]) {

    for(int i = 1; i < argc; i++) {
        std::cout << argv[i] << std::endl;
    }

    if(Client::Init() == 0) {
        Client::GameLoop();
    }
    
    return 0;
}