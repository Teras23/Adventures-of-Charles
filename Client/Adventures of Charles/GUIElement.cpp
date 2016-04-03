#include <iostream>
#include "GUIElement.h"

GUIElement::GUIElement() {
    visible = true;
}

GUIElement::GUIElement(SDL_Texture* tex, SDL_Rect* r) {
    visible = true;
    texture = tex;
    rect = r;
}

void GUIElement::Draw() {
    
}