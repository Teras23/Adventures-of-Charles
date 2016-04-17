#include "GUIText.h"

GUIText::GUIText() {
    text = "NULL";
    position = Vector2i(0, 0);
    size = Vector2i(0, 0);
    GUIElement::AddElement(this);
}

GUIText::GUIText(std::string t, Vector2i p) {
    text = t;
    position = p;
    GUIElement::AddElement(this);
}

GUIText::GUIText(std::string t, Vector2i p, Vector2i s) {
    text = t;
    position = p;
    size = s;
    GUIElement::AddElement(this);
}

void GUIText::Draw() {
    if(visible) {
        SDL_Color color;
        color.r = 0;
        color.b = 0;
        color.g = 0;
        //Normally 16 

        std::vector<size_t> positions;

        positions.push_back(0);

        std::size_t pos = text.find("\n");
        while(pos != std::string::npos) {
            positions.push_back(pos + 1);
            pos = text.find("\n", pos + 1);
        }

        positions.push_back(text.size() - 1);

        for(int i = 0; i < positions.size() - 1; i++) {
            SDL_Surface* textSurface = TTF_RenderUTF8_Blended(font, text.substr(positions[i], positions[i + 1] - 1).c_str(), color);
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
                    rect->y = position.y + i * textSurface->h;
                    rect->w = textSurface->w;
                    rect->h = textSurface->h;
                    SDL_RenderCopy(Game::renderer, textTexture, NULL, rect);
                    SDL_DestroyTexture(textTexture);
                    delete rect;
                }
            }
            SDL_FreeSurface(textSurface);
        }
    }
}

void GUIText::SetText(std::string t) {
    text = t;
}

std::string GUIText::GetText() {
    return text;
}