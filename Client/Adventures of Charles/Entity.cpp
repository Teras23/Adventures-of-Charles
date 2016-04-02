#include "Entity.h"
#include "Game.h"
#include "Input.h"
#include <iostream>
#include <SDL_image.h>

int Entity::curID = 0;

Entity::Entity() {
    id = curID;
    curID++;
    speed = 5.0f;
    position = Vector2f(300, 300);
    texture = NULL;
}

void Entity::Draw() {
    if(texture == NULL) {
        std::cout << "Missing texture!" << std::endl;
    }
    else {
        SDL_SetRenderDrawColor(Game::renderer, 0x00, 0x00, 0xFF, 0xFF);
        SDL_Rect* dest = new SDL_Rect();
        dest->x = position.x;
        dest->y = position.y;
        dest->w = 32;
        dest->h = 32;

        SDL_Rect* source = new SDL_Rect();
        source->x = 0;
        source->y = 0;
        source->w = 32;
        source->h = 32;
        SDL_RenderCopy(Game::renderer, texture, source, dest);
        delete dest;
        delete source;
        SDL_SetRenderDrawColor(Game::renderer, 0x00, 0xFF, 0xFF, 0xFF);
    }
}

void Entity::Update() {
    
}