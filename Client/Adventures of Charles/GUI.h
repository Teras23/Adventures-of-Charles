#ifndef GUI_H
#define GUI_H
#include <SDL.h>
#include <SDL_ttf.h>
#include <string>
#include <vector>
#include "Util.h"

struct GUIElement {
    SDL_Texture* texture;
    SDL_Rect* rect;
    GUIElement(SDL_Texture*, SDL_Rect*);
};

class GUI {
public:
    static std::vector<GUIElement> elements;
    static TTF_Font* font;
    static void Init();
    static void DrawText(std::string, Vector2i);
    static void Draw();
};

#endif