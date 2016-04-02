#ifndef GUITEXT_H
#define GUITEXT_H
#include "GUIElement.h"

class GUIText : public GUIElement {
public:
    static TTF_Font* font;
    std::string text;
    Vector2i position;
    Vector2i size;

    GUIText();
    GUIText(std::string, Vector2i);
    GUIText(std::string, Vector2i, Vector2i);
    void Draw();
};

#endif