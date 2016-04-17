#ifndef GAME_H
#define GAME_H
#include <SDL.h>
#include <SDL_net.h>
#include <map>
#include "Util.h"

class Game {
    static bool running;
    static SDL_Event sdlEvent;
public:
    static SDL_Window* window;
    static SDL_Surface* screen;
    static SDL_Renderer* renderer;
    static Vector2i screenSize;
    static double deltaTime;
    static double interpolation;
    static bool onlineMode;

    static std::map<std::string, SDL_Texture*> textures;

    static int Init();
    static int Quit();
    static void Loop();
    static void Update();
    static void Render();
    static void Input();
};

#endif