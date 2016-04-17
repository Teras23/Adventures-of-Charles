#include "Entity.h"
#include "Game.h"
#include "Input.h"
#include <iostream>
#include <SDL_image.h>
#include "World.h"

int Entity::curID = 0;

Entity::Entity() {
    id = curID;
    curID++;
    speed = 10.0f;
    position = Vector2f(200, 100);
    velocity = Vector2f(0, 0);
    texture = NULL;
}

void Entity::Draw() {
    if(texture == NULL) {
        Console::Print("Missing texture!");
    }
    else {
        SDL_Rect* dest = new SDL_Rect();
        dest->x = position.x - World::GetPlayer()->GetPosition().x + 400;
        dest->y = position.y - World::GetPlayer()->GetPosition().y + 300;
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
    position.x += velocity.x;
    position.y += velocity.y;
}

Vector2f Entity::GetPosition() {
    return position;
}

void Entity::SetPosition(Vector2f pos) {
    Console::Print("Position set" + std::to_string(pos.x));
    position = pos;
    Console::Print("Position set" + std::to_string(position.x));
}