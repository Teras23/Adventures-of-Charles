#include "Game.h"
#include <iostream>

bool Game::running;
SDL_Window* Game::window;
SDL_Surface* Game::screen;
SDL_Event Game::sdlEvent;

int Game::Init() {
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        std::cout << "Could not init SDL" << std::endl;
        return -1;
    }
    else {
        window = SDL_CreateWindow("AOC", 100, 100, 800, 600, SDL_WINDOW_SHOWN);
        screen = SDL_GetWindowSurface(window);
    }

    if(SDLNet_Init() < 0) {
        std::cout << "Could not init SDL_net " << SDLNet_GetError() << std::endl;
        return -1;
    }

    running = true;
    std::cout << "Game initialized" << std::endl;
    return 0;
}

int Game::Quit() {
    SDL_Quit();
    return 0;
}

void Game::Loop() {
    while(running) {
        Input();

        //Logic

        Render();
        SDL_UpdateWindowSurface(window);
    }
    Quit();
}

void Game::Input() {
    while(SDL_PollEvent(&sdlEvent) != 0) {
        if(sdlEvent.type == SDL_QUIT) {
            running = false;
        }
    }
}

void Game::Render() {
    SDL_Rect* rect = new SDL_Rect();
    rect->x = 0;
    rect->y = 0;
    rect->w = 100;
    rect->h = 100;
    SDL_FillRect(screen, rect, SDL_MapRGB(screen->format, 0xA3, 0x20, 0x40));
}