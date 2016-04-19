#ifndef MAPLAYER_H
#define MAPLAYER_H
#include <SDL.h>
#include <vector>

#include "Tile.h"

class MapLayer {
public:
    std::vector<std::vector<Tile>> tiles;

    MapLayer();
    void Draw();
};

#endif