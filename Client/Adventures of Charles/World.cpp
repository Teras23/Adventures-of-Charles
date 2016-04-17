#include "World.h"
#include "Enemy.h"
#include "Player.h"

std::vector<Entity*> World::entities;
std::vector<MapLayer> World::layers;

void World::Init() {
    entities = std::vector<Entity*>();
    entities.push_back(new Player());
    Tile::tilemap = Game::textures["Tilemap"];
    LoadMap();
}

void World::Draw() {
    for(int i = 0; i < layers.size(); i++) {
        layers[i].Draw();
    }

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
    EnemySolder* enemy = new EnemySolder();
    //enemy->SetPosition(Vector2f(World::GetPlayer()->GetPosition().x, World::GetPlayer()->GetPosition().y));
    entities.push_back(enemy);
}

void World::RemoveLastEnemy() {
    if(entities.size() != 1) {
        delete entities[entities.size() - 1];
        entities.erase(entities.begin() + entities.size() - 1);
    }
}

#define PLAYERSIZE 32

Vector2i World::GetGameMousePosition(Vector2i winPos) {
    Vector2i pos = Vector2i();
    pos.x = winPos.x + World::GetPlayer()->GetPosition().x - Game::screenSize.x / 2 + PLAYERSIZE / 2;
    pos.y = winPos.y + World::GetPlayer()->GetPosition().y - Game::screenSize.y / 2 + PLAYERSIZE / 2;
    return pos;
}