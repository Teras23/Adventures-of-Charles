#include <iostream>
#include "Game.h"
#include "World.h"
#include "Input.h"

const int FRAMERATE = 300;

bool Game::running;
SDL_Window* Game::window;
SDL_Surface* Game::screen;
SDL_Event Game::sdlEvent;
float Game::deltaTime;

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
    World::Init();
    std::cout << "Game initialized" << std::endl;
    return 0;
}

int Game::Quit() {
    SDL_Quit();
    return 0;
}

void Game::Loop() {
    int lastTime = SDL_GetTicks();
    while(running) {
        int startTime = SDL_GetTicks();
        int frameTime = startTime - lastTime;
        if(frameTime > 10) {
            std::cout << frameTime << std::endl;
        

        Input();

        //Logic
        World::Update();

        Render();
        SDL_UpdateWindowSurface(window);
        deltaTime = (SDL_GetTicks() - startTime);
        lastTime = startTime;
        }
    }
    Quit();
}

void Game::Input() {
    while(SDL_PollEvent(&sdlEvent) != 0) {
        if(sdlEvent.type == SDL_QUIT) {
            running = false;
        }
        if(sdlEvent.type == SDL_KEYDOWN) {
            switch(sdlEvent.key.keysym.sym)
            {
            case SDLK_w:

                Input::WPressed = true;
                break;
            case SDLK_s:
                std::cout << SDL_GetTicks() << std::endl;
                Input::SPressed = true;
                break;
            case SDLK_d:
                Input::DPressed = true;
                break;
            case SDLK_a:
                Input::APressed = true;
                break;
            }
        }
        if(sdlEvent.type == SDL_KEYUP) {
            switch(sdlEvent.key.keysym.sym)
            {
            case SDLK_w:
                Input::WPressed = false;
                break;
            case SDLK_s:
                Input::SPressed = false;
                break;
            case SDLK_d:
                Input::DPressed = false;
                break;
            case SDLK_a:
                Input::APressed = false;
                break;
            }
        }
    }
}

void Game::Render() {
    SDL_Rect* rect = new SDL_Rect();
    rect->x = 0;
    rect->y = 0;
    rect->w = 800;
    rect->h = 600;
    SDL_FillRect(screen, rect, SDL_MapRGB(screen->format, 0xA3, 0x20, 0x40));
    World::Draw();
}