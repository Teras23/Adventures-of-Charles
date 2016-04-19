#include "MapLayer.h"
#include "World.h"
#include "../Client/Game.h"

MapLayer::MapLayer() {

}

#define TILESIZE 32
#define PLAYERSIZE 32

void MapLayer::Draw() {
    SDL_Rect* dest = new SDL_Rect();
    SDL_Rect* source = new SDL_Rect();

    dest->w = TILESIZE;
    dest->h = TILESIZE;

    source->w = TILESIZE;
    source->h = TILESIZE;

    for(int y = 0; y < tiles.size(); y++) {
        for(int x = 0; x < tiles[0].size(); x++) {
            int tileId = tiles[y][x].id;

            dest->x = x * TILESIZE - World::GetPlayer()->GetPosition().x + Game::screenSize.x / 2 - PLAYERSIZE / 2;
            dest->y = y * TILESIZE - World::GetPlayer()->GetPosition().y + Game::screenSize.y / 2 - PLAYERSIZE / 2;
            
            source->x = (tileId - 1) % 8 * TILESIZE;
            source->y = (tileId - 1) / 8 * TILESIZE;
            
            SDL_RenderCopy(Game::renderer, Tile::tilemap, source, dest);
        }
    }
    delete dest;
    delete source;
}