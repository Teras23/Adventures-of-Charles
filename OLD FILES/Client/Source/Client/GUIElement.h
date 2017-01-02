#ifndef GUIELEMENT_H
#define GUIELEMENT_H
#include <SDL.h>
#include "../Shared/Util.h"
#include "Game.h"

class GUIElement {
private:
    std::string name;
protected:
    bool lastClickState;
    bool visible;
    bool clickable;
    bool clicked;
    Vector2i position;
    Vector2i size;
public:
    SDL_Rect* source;
    SDL_Rect* dest;

    static TTF_Font* font;

    GUIElement();
    void AddElement(GUIElement* element);
    virtual void Draw();

    void Update();

    virtual void SetText(std::string text);
    virtual std::string GetText();

    bool IsPressed();
    void SetPressed(bool state);

    bool IsClickable();

    void SetVisibility(bool visibility);

    void SetName(std::string name);
    std::string GetName();

    Vector2i GetSize();
    Vector2i GetPosition();

    virtual void OnHover();
    virtual void OnClick();
};

#endif