#include <SDL_image.h>
#include <iostream>
#include <fstream>

#include "Util.h"
#include "../Client/Game.h"
#include "World.h"

Vector2i::Vector2i() {
    x = 0;
    y = 0;
}

Vector2i::Vector2i(int x, int y) {
    this->x = x;
    this->y = y;
}

Vector2f::Vector2f() {
    x = 0;
    y = 0;
}

Vector2f::Vector2f(float x, float y) {
    this->x = x;
    this->y = y;
}

void Console::Print(std::string msg) {
    std::cout << msg << std::endl;
}

void Console::PrintError(std::string msg) {
    std::cout << "Error: " << msg << std::endl;
}

void Console::PrintError(std::string msg, const char* errorMsg) {
    std::cout << "Error: " << msg << " - " << errorMsg << std::endl;
}

//TODO: recompile png thing
SDL_Texture* LoadTexture(std::string path) {
    SDL_Texture* texture = NULL;
    SDL_Surface* textureSurface = IMG_Load(path.c_str());

    Console::Print("Loaded " + path);

    if(textureSurface == NULL) {
        std::cout << "Failed to load image  " << path << std::endl;
    }
    else {
        texture = SDL_CreateTextureFromSurface(Game::renderer, textureSurface);
        if(texture == NULL) {
            std::cout << "Failed to create texture " << path << std::endl;
        }
        SDL_FreeSurface(textureSurface);
    }
    return texture;
}

TTF_Font* LoadFont(std::string path) {
    TTF_Font* font = NULL;
    //28 is font size, different sizes may look different
    font = TTF_OpenFont(path.c_str(), 12);
    if(font == NULL) {
        std::cout << "Failed to load font " << path << std::endl;
    }
    TTF_SetFontHinting(font, TTF_HINTING_NORMAL);
    return font;
}

void SaveMap() {
    std::vector<std::vector<Tile>> map = World::layers[0].tiles;

    std::ofstream ofile("Resources/map.txt");
    ofile << map[0].size() << " " << map.size() << " " << World::layers.size() << std::endl;
    for(int y = 0; y < map.size(); y++) {
        for(int x = 0; x < map[0].size(); x++) {
            ofile << map[y][x].id << " ";
        }
        ofile << std::endl;
    }
    ofile.close();
}

void LoadMap() {
    std::ifstream ifile("Resources/map.txt");
    std::vector<MapLayer> mapLayers;

    int w, h, l;
    ifile >> w >> h >> l;
    std::vector<std::vector<Tile>> map;
    for(int y = 0; y < h; y++) {
        std::vector<Tile> row;
        for(int x = 0; x < w; x++) {
            int tileId = 0;
            ifile >> tileId;
            row.push_back(Tile(tileId));
        }
        map.push_back(row);
    }
    MapLayer layer = MapLayer();
    layer.tiles = map;
    mapLayers.push_back(layer);
    World::layers = mapLayers;
    ifile.close();
}