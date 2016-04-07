#include "GUICheckbox.h"

GUICheckbox::GUICheckbox() {
    checked = false;
    position = Vector2i(0, 0);
    GUIElement::AddElement(this);
}

GUICheckbox::GUICheckbox(bool c, Vector2i p) {
    checked = c;
    position = p;
    GUIElement::AddElement(this);
}

void GUICheckbox::Draw() {
    if(visible) {
        
    }
}