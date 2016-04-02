#include "Util.h"
#include <SDL_image.h>
#include <iostream>
#include "Game.h"

Vector2i::Vector2i() {
    x = 0;
    y = 0;
}

Vector2i::Vector2i(int x, int y) {
    this->x = x;
    this->y = y;
}

Vector2f::Vector2f() {
    x = 0;
    y = 0;
}

Vector2f::Vector2f(float x, float y) {
    this->x = x;
    this->y = y;
}

void Console::Print(std::string msg) {
#if SERVER
    //std::cout << "server :)" << std::endl;
#elif CLIENT
    //std::cout << "YOYO" << std::endl;
#endif
    std::cout << msg << std::endl;
}

void Console::PrintError(std::string msg) {
    std::cout << "Error: " << msg << std::endl;
}

void Console::PrintError(std::string msg, const char* errorMsg) {
    std::cout << "Error: " << msg << " - " << errorMsg << std::endl;
}

//TODO: recompile png thing
SDL_Texture* LoadTexture(std::string path) {
    SDL_Texture* texture = NULL;
    SDL_Surface* textureSurface = IMG_Load(path.c_str());

    if(textureSurface == NULL) {
        std::cout << "Failed to load image  " << path << std::endl;
    }
    else {
        texture = SDL_CreateTextureFromSurface(Game::renderer, textureSurface);
        if(texture == NULL) {
            std::cout << "Failed to create texture " << path << std::endl;
        }
        SDL_FreeSurface(textureSurface);
    }
    return texture;
}

TTF_Font* LoadFont(std::string path) {
    TTF_Font* font = NULL;
    //28 is font size, different sizes may look different
    font = TTF_OpenFont(path.c_str(), 12);
    if(font == NULL) {
        std::cout << "Failed to load font " << path << std::endl;
    }
    TTF_SetFontHinting(font, TTF_HINTING_NORMAL);
    return font;
}