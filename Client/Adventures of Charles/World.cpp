#include "World.h"
#include "Enemy.h"

std::vector<Entity*> World::entities;

void World::Init() {
    entities = std::vector<Entity*>();
    entities.push_back(new Entity());
}

void World::Draw() {
    for(int i = 0; i < entities.size(); i++) {
        entities[i]->Draw();
    }
}

void World::Update() {
    for(int i = 0; i < entities.size(); i++) {
        entities[i]->Update();
    }
}

Entity* World::GetPlayer() {
    if(entities.size() > 0) {
        return entities[0];
    }
    else {
        return NULL;
    }
}

void World::AddEnemy() {
    entities.push_back(new EnemyBase());
}

void World::RemoveLastEnemy() {
    delete entities[entities.size() - 1];
    entities.erase(entities.begin() + entities.size() - 1);
}