#include "Sprite.h"
#include "Util.h"
#include "World.h"
#include "Game.h"

Sprite::Sprite() {
    texture = NULL;
}

#define PLAYERSIZE 32

void Sprite::Draw(Vector2f position, Vector2f texturePosition) {
    if(texture == NULL) {
        Console::PrintError("Sprite missing texture!");
    }
    else {
        SDL_Rect* dest = new SDL_Rect();
        dest->x = position.x;
        dest->y = position.y;
        dest->w = TILESIZE;
        dest->h = TILESIZE;

        SDL_Rect* source = new SDL_Rect();
        source->x = 0;
        source->y = 0;
        source->w = TILESIZE;
        source->h = TILESIZE;

        SDL_RenderCopy(Game::renderer, texture, source, dest);

        delete dest;
        delete source;
    }
}