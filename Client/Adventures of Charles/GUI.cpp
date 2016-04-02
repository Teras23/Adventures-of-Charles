#include "GUI.h"
#include <iostream>
#include "Game.h"

std::vector<GUIElement*> GUI::elements;

void GUI::Init() {
    //font = LoadFont("FreeSans.ttf");
    GUIText::font = LoadFont("PixelFJVerdana12pt.ttf");
}

void GUI::Draw() {
    for(int i = 0; i < elements.size(); i++) {
        elements[i]->Draw();
        /*SDL_RenderCopy(Game::renderer, elements[i].texture, NULL, elements[i].rect);
        SDL_DestroyTexture(elements[i].texture);
        delete elements[i].rect;*/
    }
    elements = std::vector<GUIElement*>();
}

void GUI::DrawText(std::string text, Vector2i position) {
    elements.push_back(new GUIText(text, position));
}

void GUI::DrawBox(Vector2i position, Vector2i size) {
    elements.push_back(new GUIBox(position, size));
}