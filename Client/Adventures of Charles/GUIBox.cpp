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

void GUIBox::Draw() {
    if(visible) {
        SDL_Rect* source = new SDL_Rect();
        SDL_Rect* dest = new SDL_Rect();

        /*
        TOP LEFT
        */
        source->x = 0;
        source->y = 0;
        source->w = 8;
        source->h = 8;

        dest->x = position.x;
        dest->y = position.y;
        dest->w = 8;
        dest->h = 8;
        SDL_RenderCopy(Game::renderer, texture, source, dest);

        /*
        TOP MIDDLE
        */
        source->x = 8;
        dest->x = position.x + 8;
        dest->w = size.x - 2 * 8;
        SDL_RenderCopy(Game::renderer, texture, source, dest);

        /*
        TOP RIGHT
        */
        source->x = 2 * 8;
        dest->x = position.x + size.x - 8;
        dest->w = 8;
        SDL_RenderCopy(Game::renderer, texture, source, dest);

        /*
        MIDDLE LEFT
        */
        source->x = 0;
        source->y = 8;

        dest->x = position.x;
        dest->y = position.y + 8;
        dest->w = 8;
        dest->h = size.y - 2 * 8;
        SDL_RenderCopy(Game::renderer, texture, source, dest);

        /*
        MIDDLE MIDDLE
        */
        source->x = 8;
        dest->x = position.x + 8;
        dest->w = size.x - 2 * 8;
        SDL_RenderCopy(Game::renderer, texture, source, dest);

        /*
        MIDDLE RIGHT
        */
        source->x = 2 * 8;
        dest->x = position.x + size.x - 8;
        dest->w = 8;
        SDL_RenderCopy(Game::renderer, texture, source, dest);

        /*
        BOTTOM LEFT
        */
        source->x = 0;
        source->y = 2 * 8;

        dest->x = position.x;
        dest->y = position.y + size.y - 8;
        dest->w = 8;
        dest->h = 8;
        SDL_RenderCopy(Game::renderer, texture, source, dest);

        /*
        BOTTOM MIDDLE
        */
        source->x = 8;
        dest->x = position.x + 8;
        dest->w = size.x - 2 * 8;
        SDL_RenderCopy(Game::renderer, texture, source, dest);

        /*
        BOTTOM RIGHT
        */
        source->x = 2 * 8;
        dest->x = position.x + size.x - 8;
        dest->w = 8;
        SDL_RenderCopy(Game::renderer, texture, source, dest);

        delete source;
        delete dest;
    }
}