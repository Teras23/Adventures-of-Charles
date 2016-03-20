#ifndef CLIENT_H
#define CLIENT_H
#include <SDL.h>
#include <SDL_net.h>

class Client {
    int clientid;
    static bool running;
    static SDL_Window* window;
    static SDL_Surface* screen;
    static SDL_Event sdlEvent;
public:
    static int Init();
    static int Quit();
    static void GameLoop();
    static void Render();
    static void Input();
};

#endif