#include "GUIButton.h"
#include "GUIText.h"
#include "GUIBox.h"

TTF_Font* GUIButton::font = NULL;
SDL_Texture* GUIButton::texture = NULL;

GUIButton::GUIButton() {
    text = "NULL";
    position = Vector2i(0, 0);
    size = Vector2i(0, 0);
    clickable = true;
    SetName("Button");
    GUIElement::AddElement(this);
}

GUIButton::GUIButton(std::string t, Vector2i p, Vector2i s) {
    text = t;
    position = p;
    size = s;
    clickable = true;
    SetName("Button");
    GUIElement::AddElement(this);
}

void GUIButton::Draw() {
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

        /*SDL_Color color;
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
        SDL_FreeSurface(textSurface);*/
    }
}