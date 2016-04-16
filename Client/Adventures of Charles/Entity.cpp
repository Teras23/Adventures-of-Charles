#include "Entity.h"
#include "Game.h"
#include "Input.h"
#include <iostream>
#include <SDL_image.h>

int Entity::curID = 0;

Entity::Entity() {
    id = curID;
    curID++;
    speed = 10.0f;
    position = Vector2f(300, 300);
    texture = NULL;
}

void Entity::Draw() {
    if(texture == NULL) {
        std::cout << "Missing texture!" << std::endl;
    }
    else {
        SDL_Rect* dest = new SDL_Rect();
        dest->x = position.x + velocity.x * Game::interpolation;
        dest->y = position.y + velocity.y * Game::interpolation;
        dest->w = TILESIZE;
        dest->h = TILESIZE;

        SDL_Rect* source = new SDL_Rect();
        source->x = 0;
        source->y = 0;
        source->w = TILESIZE;
        source->h = TILESIZE;
        SDL_RenderCopy(Game::renderer, texture, source, dest);
        delete dest;
        delete source;
    }
}

void Entity::Update() {
    
}