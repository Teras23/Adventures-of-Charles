#include "World.h"
#include "Enemy.h"
#include "Player.h"

std::vector<std::vector<Tile>> World::tiles;
std::vector<Entity*> World::entities;

void World::Init() {
    entities = std::vector<Entity*>();
    entities.push_back(new Player());
    Tile::tilemap = LoadTexture("Textures/tilemap.png");
    tiles = LoadMap();
}

void World::Draw() {
    for(int y = 0; y < tiles.size(); y++) {
        for(int x = 0; x < tiles[0].size(); x++) {
            int tileId = tiles[y][x].id;
            SDL_Rect* dest = new SDL_Rect();
            dest->x = x * TILESIZE;
            dest->y = y * TILESIZE;
            dest->w = TILESIZE;
            dest->h = TILESIZE;

            SDL_Rect* source = new SDL_Rect();
            source->x = (tileId - 1) % 8 * TILESIZE;
            source->y = (tileId - 1) / 8 * TILESIZE;
            source->w = TILESIZE;
            source->h = TILESIZE;
            SDL_RenderCopy(Game::renderer, Tile::tilemap, source, dest);
            delete dest;
            delete source;
        }
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
    entities.push_back(new EnemySolder());
}

void World::RemoveLastEnemy() {
    delete entities[entities.size() - 1];
    entities.erase(entities.begin() + entities.size() - 1);
}