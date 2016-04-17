#include "MapLayer.h"
#include "Game.h"
#include "World.h"

MapLayer::MapLayer() {

}

#define TILESIZE 32

void MapLayer::Draw() {
    for(int y = 0; y < tiles.size(); y++) {
        for(int x = 0; x < tiles[0].size(); x++) {
            int tileId = tiles[y][x].id;
            SDL_Rect* dest = new SDL_Rect();
            dest->x = x * TILESIZE - World::GetPlayer()->GetPosition().x + 400;
            dest->y = y * TILESIZE - World::GetPlayer()->GetPosition().y + 300;
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
}