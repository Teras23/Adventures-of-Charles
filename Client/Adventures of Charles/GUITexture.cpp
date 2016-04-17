#include "GUITexture.h"

GUITexture::GUITexture() {
    clickable = false;
    SetName("GUITexture");
    texture = NULL;
    GUIElement::AddElement(this);
}

GUITexture::GUITexture(Vector2i p, Vector2i s, SDL_Texture* tex) {
    clickable = false;
    position = p;
    size = s;
    texture = tex;
    SetName("GUITexture");
    GUIElement::AddElement(this);
}

void GUITexture::Draw() {
    if(texture == NULL) {
        Console::Print("No Texture!");
    }
    else if(visible) {
        SDL_Rect* source = new SDL_Rect();
        SDL_Rect* dest = new SDL_Rect();

        dest->x = position.x;
        dest->y = position.y;
        dest->w = size.x;
        dest->h = size.y;

        source->x = 0;
        source->y = 0;
        source->w = 32;
        source->h = 32;

        SDL_RenderCopy(Game::renderer, texture, source, dest);

        delete source;
        delete dest;
    }
}