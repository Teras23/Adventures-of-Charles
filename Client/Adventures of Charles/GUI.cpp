#include "GUI.h"
#include <iostream>
#include "Game.h"

TTF_Font* GUI::font;
std::vector<GUIElement> GUI::elements;

GUIElement::GUIElement(SDL_Texture* tex, SDL_Rect* r) {
    texture = tex;
    rect = r;
}

void GUI::Init() {
    font = LoadFont("FreeSans.ttf");
}

void GUI::Draw() {
    for(int i = 0; i < elements.size(); i++) {
        SDL_RenderCopy(Game::renderer, elements[i].texture, NULL, elements[i].rect);
    }
    elements = std::vector<GUIElement>();
}

void GUI::DrawText(std::string text, Vector2i position) {
    SDL_Color color;
    color.r = 0;
    color.b = 0;
    color.g = 0;
    SDL_Surface* textSurface = TTF_RenderText_Solid(font, text.c_str(), color);
    if(textSurface == NULL) {
        std::cout << "Unable to render text to surface " << TTF_GetError() << std::endl;
    }
    else {
        SDL_Texture* textTexture = SDL_CreateTextureFromSurface(Game::renderer, textSurface);
        if(textTexture == NULL) {
            std::cout << "Unable to create text texture from surface " << SDL_GetError() << std::endl;
        }
        else {
            SDL_Rect* rect = new SDL_Rect();
            rect->x = position.x;
            rect->y = position.y;
            rect->w = textSurface->w;
            rect->h = textSurface->h;
            elements.push_back(GUIElement(textTexture, rect));
        }
    }
}