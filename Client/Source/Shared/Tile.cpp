#include "Tile.h"

SDL_Texture* Tile::tilemap;

Tile::Tile() {
    id = 0;
}

Tile::Tile(int i) {
    id = i;
}