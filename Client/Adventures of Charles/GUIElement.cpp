#include <iostream>
#include "GUIElement.h"

GUIElement::GUIElement() {

}

GUIElement::GUIElement(SDL_Texture* tex, SDL_Rect* r) {
    texture = tex;
    rect = r;
}

void GUIElement::Draw() {
    
}