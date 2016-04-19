#include <iostream>
#include "GUIBox.h"

SDL_Texture* GUIBox::texture = NULL;

GUIBox::GUIBox() {
    clickable = true;
    SetName("GUIBox");
    GUIElement::AddElement(this);
}

GUIBox::GUIBox(Vector2i p, Vector2i s) {
    clickable = true;
    position = p;
    size = s;
    SetName("GUIBox");
    GUIElement::AddElement(this);
}

#define GRID 8

void GUIBox::Draw() {
    if(visible) {
        SDL_Rect* source = new SDL_Rect();
        SDL_Rect* dest = new SDL_Rect();

        /*
        TOP LEFT
        */
        source->x = 0;
        source->y = 0;
        source->w = GRID;
        source->h = GRID;

        dest->x = position.x;
        dest->y = position.y;
        dest->w = GRID;
        dest->h = GRID;
        SDL_RenderCopy(Game::renderer, texture, source, dest);

        /*
        TOP MIDDLE
        */
        source->x = GRID;
        dest->x = position.x + GRID;
        dest->w = size.x - 2 * GRID;
        SDL_RenderCopy(Game::renderer, texture, source, dest);

        /*
        TOP RIGHT
        */
        source->x = 2 * GRID;
        dest->x = position.x + size.x - GRID;
        dest->w = GRID;
        SDL_RenderCopy(Game::renderer, texture, source, dest);

        /*
        MIDDLE LEFT
        */
        source->x = 0;
        source->y = GRID;

        dest->x = position.x;
        dest->y = position.y + GRID;
        dest->w = GRID;
        dest->h = size.y - 2 * GRID;
        SDL_RenderCopy(Game::renderer, texture, source, dest);

        /*
        MIDDLE MIDDLE
        */
        source->x = GRID;
        dest->x = position.x + GRID;
        dest->w = size.x - 2 * GRID;
        SDL_RenderCopy(Game::renderer, texture, source, dest);

        /*
        MIDDLE RIGHT
        */
        source->x = 2 * GRID;
        dest->x = position.x + size.x - GRID;
        dest->w = GRID;
        SDL_RenderCopy(Game::renderer, texture, source, dest);

        /*
        BOTTOM LEFT
        */
        source->x = 0;
        source->y = 2 * GRID;

        dest->x = position.x;
        dest->y = position.y + size.y - GRID;
        dest->w = GRID;
        dest->h = GRID;
        SDL_RenderCopy(Game::renderer, texture, source, dest);

        /*
        BOTTOM MIDDLE
        */
        source->x = GRID;
        dest->x = position.x + GRID;
        dest->w = size.x - 2 * GRID;
        SDL_RenderCopy(Game::renderer, texture, source, dest);

        /*
        BOTTOM RIGHT
        */
        source->x = 2 * GRID;
        dest->x = position.x + size.x - GRID;
        dest->w = GRID;
        SDL_RenderCopy(Game::renderer, texture, source, dest);

        delete source;
        delete dest;
    }
}