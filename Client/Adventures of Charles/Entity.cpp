#include "Entity.h"
#include "Game.h"
#include "Input.h"
#include <iostream>

Entity::Entity() {
    speed = 10000.0f;
}

void Entity::Draw() {
    SDL_Rect* rect = new SDL_Rect();
    rect->x = position.x;
    rect->y = position.y;
    rect->w = 32;
    rect->h = 32;
    SDL_FillRect(Game::screen, rect, SDL_MapRGB(Game::screen->format, 0x00, 0x00, 0xFF));
    delete rect;
}

void Entity::Update() {
    velocity.x = 0;
    velocity.y = 0;
    if(Input::WPressed) {
        velocity.y = -1 * speed * Game::deltaTime;
        std::cout << Game::deltaTime << std::endl;
    }
    if(Input::SPressed) {
        velocity.y = 1 * speed * Game::deltaTime;
    }
    if(Input::DPressed) {
        velocity.x = 1 * speed * Game::deltaTime;
    }
    if(Input::APressed) {
        velocity.x = -1 * speed * Game::deltaTime;
    }
    position.x += velocity.x;
    position.y += velocity.y;
}