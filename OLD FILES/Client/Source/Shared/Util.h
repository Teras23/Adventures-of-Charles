#ifndef UTIL_H
#define UTIL_H
#include <SDL.h>
#include <SDL_ttf.h>

#include <string>
#include <vector>

#include "Tile.h"

#define TILESIZE 32

class Vector2i {
public:
    Vector2i();
    Vector2i(int x, int y);
    int x;
    int y;
};

class Vector2f {
public:
    Vector2f();
    Vector2f(float x, float y);
    float x;
    float y;
};

class Rect {
public:
    Rect();
    Rect(int x, int y, int w, int h);
    int x;
    int y;
    int w;
    int h;
    SDL_Rect* GetSDLRect();
};

class Console {
public:
    static void Print(std::string text);
    static void PrintError(std::string errortext);
    static void PrintError(std::string text, const char* error);
};

SDL_Texture* LoadTexture(std::string);
TTF_Font* LoadFont(std::string);
void SaveMap();
void LoadMap();

#endif