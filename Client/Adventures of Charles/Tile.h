#ifndef TILE_H
#define TILE_H
#include <SDL.h>

class Tile {
public:
    static SDL_Texture* tilemap;
    int id;
    Tile();
    Tile(int id);
};

#endif