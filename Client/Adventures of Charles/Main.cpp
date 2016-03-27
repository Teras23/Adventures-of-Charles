#include <SDL_net.h>
#include <iostream>
#include "Game.h"

int main(int argc, char* argv[]) {

    for(int i = 1; i < argc; i++) {
        std::cout << argv[i] << std::endl;
    }
    
    if(Game::Init() == 0) {
        Game::Loop();
    }
    
    return 0;
}