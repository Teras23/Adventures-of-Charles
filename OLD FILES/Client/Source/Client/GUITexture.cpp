#include "GUITexture.h"

GUITexture::GUITexture() {
    clickable = false;
    texture = NULL;
    source = new SDL_Rect();
    source->x = 0;
    source->y = 0;
    source->w = 32;
    source->h = 32;

    SetName("GUITexture");
    GUIElement::AddElement(this);
}

GUITexture::GUITexture(Vector2i p, Vector2i s, SDL_Texture* tex) {
    clickable = false;
    position = p;
    size = s;
    texture = tex;
    source = new SDL_Rect();
    source->x = 0;
    source->y = 0;
    source->w = 32;
    source->h = 32;

    SetName("GUITexture");
    GUIElement::AddElement(this);
}

void GUITexture::Draw() {
    if(texture == NULL) {
        Console::Print("No Texture!");
    }
    else if(visible) {
        SDL_Rect* dest = new SDL_Rect();

        dest->x = position.x;
        dest->y = position.y;
        dest->w = size.x;
        dest->h = size.y;

        SDL_RenderCopy(Game::renderer, texture, source, dest);

        delete dest;
    }
}