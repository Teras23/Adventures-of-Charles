#include "Entity.h"
#include "World.h"
#include "../Client/Game.h"
#include "../Client/Input.h"

int Entity::curId = 0;

Entity::Entity() {
    type = ENTITY_UNDEFINED;
    id = curId;
    curId++;

    position = Vector2f(0, 0);
    velocity = Vector2f(0, 0);

    speed = 10.0f;
    collider = Rect(0, 0, 32, 32);

    maxHealth = 100;
    health = maxHealth;

    isAlive = true;
    isVisible = true;
    isStatic = false;
    isCollidable = true;
}

void Entity::Use() {
    Console::Print(std::to_string(type) + " with id " + std::to_string(id) + " was used");
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

EntityType Entity::GetType() {
    return type;
}

Rect Entity::GetCollider() {
    return collider;
}