#include "GUIText.h"

TTF_Font* GUIText::font = NULL;

GUIText::GUIText() {
    text = "NULL";
    position = Vector2i(0, 0);
    size = Vector2i(0, 0);
}

GUIText::GUIText(std::string t, Vector2i p) {
    text = t;
    position = p;
}

GUIText::GUIText(std::string t, Vector2i p, Vector2i s) {
    text = t;
    position = p;
    size = s;
}

void GUIText::Draw() {
    SDL_Color color;
    color.r = 0;
    color.b = 0;
    color.g = 0;
    SDL_Surface* textSurface = TTF_RenderUTF8_Blended(font, text.c_str(), color);
    if(textSurface == NULL) {
        Console::PrintError("Unable to render text to surface", TTF_GetError());
    }
    else {
        SDL_Texture* textTexture = SDL_CreateTextureFromSurface(Game::renderer, textSurface);
        if(textTexture == NULL) {
            Console::PrintError("Unable to create text texture from surface", SDL_GetError());
        }
        else {
            SDL_Rect* rect = new SDL_Rect();
            rect->x = position.x;
            rect->y = position.y;
            rect->w = textSurface->w;
            rect->h = textSurface->h;
            SDL_RenderCopy(Game::renderer, textTexture, NULL, rect);
            SDL_DestroyTexture(textTexture);
        }
    }
    SDL_FreeSurface(textSurface);
}