#ifndef GUITEXT_H
#define GUITEXT_H
#include "GUIElement.h"

class GUIText : public GUIElement {
public:
    static TTF_Font* font;
    std::string text;

    GUIText();
    GUIText(std::string text, Vector2i position);
    GUIText(std::string text, Vector2i position, Vector2i size);
    void Draw();

    void SetText(std::string);
    std::string GetText();
};

#endif