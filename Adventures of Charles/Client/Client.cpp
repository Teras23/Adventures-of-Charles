#include "Client.h"
#include <iostream>

bool Client::running;
SDL_Window* Client::window;
SDL_Surface* Client::screen;

int Client::Init() {
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        std::cout << "Could not init SDL" << std::endl;
        return -1;
    }
    else {
        window = SDL_CreateWindow("AOC", 100, 100, 800, 600, SDL_WINDOW_SHOWN);
        screen = SDL_GetWindowSurface(window);
        std::cout << "SDL Initialized" << std::endl;
    }
    running = true;
    return 0;
}

int Client::Quit() {
    SDL_Quit();
    return 0;
}

void Client::GameLoop() {
    SDL_Event evt;
    while(running) {
        while(SDL_PollEvent(&evt) != 0) {
           if(evt.type == SDL_QUIT) {
                running = false;
            }
        }
        SDL_UpdateWindowSurface(window);
    }
    Quit();
}