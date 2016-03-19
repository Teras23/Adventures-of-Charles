#include <SDL.h>
#include <SDL_net.h>
#include <iostream>

int main(int argc, char* argv[]) {
    bool running = true;
    SDL_Init(SDL_INIT_EVERYTHING);
    SDLNet_Init();
    std::cout << "Initialized" << std::endl;
    SDL_Event evt;
    SDL_Window* window = SDL_CreateWindow("AOC", 100, 100, 800, 600, SDL_WINDOW_SHOWN);
    SDL_Surface* screen = SDL_GetWindowSurface(window);
    while(running) {
        while(SDL_PollEvent(&evt) != 0) {
            if(evt.type == SDL_QUIT) {
                running = false;
            }
        }
        SDL_UpdateWindowSurface(window);
    }
    SDL_Quit();
    return 0;
}