#include "Util.h"
#include "GUIElement.h"
#include "GUI.h"

GUIElement::GUIElement() {
    SetName("Name");
    visible = true;
    clickable = false;
    pressed = false;
}

void GUIElement::AddElement(GUIElement* element) {
    GUI::AddElement(element);
}

void GUIElement::Draw() {
    
}

void GUIElement::SetName(std::string n) {
    GUI::RemoveElement(name);
    name = n;
    GUI::AddElement(this);
}

std::string GUIElement::GetName() {
    return name;
}

void GUIElement::SetText(std::string) {

}

std::string GUIElement::GetText() {
    return NULL;
}

bool GUIElement::IsPressed() {
    return pressed;
}

void GUIElement::SetPressed(bool p) {
    pressed = p;
}

bool GUIElement::IsClickable() {
    return clickable;
}

Vector2i GUIElement::GetPosition() {
    return position;
}

Vector2i GUIElement::GetSize() {
    return size;
}

void GUIElement::OnHover() {

}

void GUIElement::OnClick() {

}