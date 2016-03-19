#ifndef CLIENT_H
#define CLIENT_H
#include <SDL.h>

class Client {
    int clientid;
    static bool running;
    static SDL_Window* window;
    static SDL_Surface* screen;
public:
    static int Init();
    static int Quit();
    static void GameLoop();
};

#endif