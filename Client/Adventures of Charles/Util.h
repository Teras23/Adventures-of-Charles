#ifndef UTIL_H
#define UTIL_H
#include <SDL.h>
#include <SDL_ttf.h>
#include <string>

class Vector2i {
public:
    Vector2i();
    Vector2i(int, int);
    int x;
    int y;
};

class Vector2f {
public:
    Vector2f();
    Vector2f(float, float);
    float x;
    float y;
};

class Console {
public:
    static void Print(std::string);
};

SDL_Texture* LoadTexture(std::string);
TTF_Font* LoadFont(std::string);

#endif