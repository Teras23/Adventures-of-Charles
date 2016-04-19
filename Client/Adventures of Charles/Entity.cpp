#include "Entity.h"
#include "Game.h"
#include "Input.h"
#include <iostream>
#include <SDL_image.h>
#include "World.h"

int Entity::curId = 0;

Entity::Entity() {
    type = ENTITY_UNDEFINED;
    id = curId;
    curId++;

    position = Vector2f(0, 0);
    velocity = Vector2f(0, 0);

    speed = 10.0f;

    maxHealth = 100;
    health = maxHealth;

    isAlive = true;
    isVisible = true;
    isStatic = false;
}

#define PLAYERSIZE 32

void Entity::Draw() {
    if(isVisible) {
        sprite.Draw(Vector2f(position.x - World::GetPlayer()->GetPosition().x + Game::screenSize.x / 2 - PLAYERSIZE / 2,
            position.y - World::GetPlayer()->GetPosition().y + Game::screenSize.y / 2 - PLAYERSIZE / 2), Vector2f());
    }
}

void Entity::Update() {
    if(health <= 0) {
        isAlive = false;
    }

    if(!isStatic) {
        //Check for collision
        position.x += velocity.x;
        position.y += velocity.y;
    }
}

Vector2f Entity::GetPosition() {
    return position;
}

void Entity::SetPosition(Vector2f pos) {
    position = pos;
}