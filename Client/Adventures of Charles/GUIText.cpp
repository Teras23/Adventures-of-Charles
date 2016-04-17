#include "GUIText.h"

GUIText::GUIText() {
    SetText("NULL");
    position = Vector2i(0, 0);
    size = Vector2i(0, 0);
    GUIElement::AddElement(this);
}

GUIText::GUIText(std::string t, Vector2i p) {
    SetText(t);
    position = p;
    GUIElement::AddElement(this);
}

GUIText::GUIText(std::string t, Vector2i p, Vector2i s) {
    SetText(t);
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

        for(int i = 0; i < lines.size(); i++) {
            SDL_Surface* textSurface = TTF_RenderUTF8_Blended(font, lines[i].c_str(), color);
            //Console::Print(text.substr(positions[i], positions[i + 1] - 10));
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
    lines = std::vector<std::string>();
    t += "\n";

    std::size_t lastPos = 0;
    std::size_t pos = t.find("\n");
    while(pos != std::string::npos) {
        lines.push_back(t.substr(lastPos, pos - lastPos ));
        lastPos = pos + 1;
        pos = t.find("\n", pos + 1);
    }
}

std::string GUIText::GetText() {
    std::string text;
    for(int i = 0; i < lines.size(); i++) {
        if(i != lines.size() - 1) {
            text += lines[i] + "\n";
        }
        else {
            text += lines[i];
        }
    }
    return text;
}