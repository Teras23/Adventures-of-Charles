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
    std::cout << texture << std::endl;
    return texture;
}