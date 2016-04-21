#include "World.h"
#include "Enemy.h"
#include "../Client/Game.h"
#include "../Client/Player.h"
#include "Collision.h"

std::vector<Entity*> World::entities;
std::vector<MapLayer> World::layers;

void World::Init() {
    entities = std::vector<Entity*>();
    entities.push_back(new Player());

    AddEnemy();

    Tile::tilemap = Game::textures["Tilemap"];
    LoadMap();
}

void World::Draw() {
    layers[0].Draw();

    layers[1].Draw();
    for(int i = 0; i < entities.size(); i++) {
        entities[i]->Draw();
    }

    layers[2].Draw();
}

void World::Update() {

    Collision::TestCollision(entities[0], entities[1]);

    for(int i = 0; i < entities.size(); i++) {
        entities[i]->Update();
    }
}

Entity* World::GetPlayer() {
    for(int i = 0; i < entities.size(); i++) {
        if(entities[i]->GetType() == ENTITY_PLAYER) {
            return entities[i];
        }
    }
    return NULL;
}

void World::AddEnemy() {
    EnemySolder* enemy = new EnemySolder();
    enemy->SetPosition(Vector2f(World::GetPlayer()->GetPosition().x, World::GetPlayer()->GetPosition().y + 40));
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