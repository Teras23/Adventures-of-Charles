#ifndef GAME_H
#define GAME_H
#include <SDL.h>
#include <SDL_net.h>

class Game {
    int gameid;
    static bool running;
    static SDL_Window* window;
    static SDL_Event sdlEvent;
public:
    static SDL_Surface* screen;

    static int Init();
    static int Quit();
    static void Loop();
    static void Render();
    static void Input();
};

#endif