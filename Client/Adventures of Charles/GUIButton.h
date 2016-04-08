#ifndef GUIBUTTON_H
#define GUIBUTTON_H
#include "GUIElement.h"
#include "GUIBox.h"
#include "GUIText.h"

class GUIButton : public GUIElement {
public:
    static TTF_Font* font;
    static SDL_Texture* texture;

    std::string text;
    GUIText* buttonText;
    GUIBox* buttonBox;

    GUIButton();
    GUIButton(std::string text, Vector2i position, Vector2i size);
    void Draw();
};

#endif