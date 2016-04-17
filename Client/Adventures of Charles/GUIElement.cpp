#include "Util.h"
#include "GUIElement.h"
#include "GUI.h"

TTF_Font* GUIElement::font = NULL;

GUIElement::GUIElement() {
    SetName("Name");
    visible = true;
    clickable = false;
    clicked = false;
    lastClickState = false;
}

void GUIElement::AddElement(GUIElement* element) {
    GUI::AddElement(element);
}

void GUIElement::Draw() {
    
}

void GUIElement::Update() {
    lastClickState = clicked;
}

void GUIElement::SetName(std::string n) {
    std::string oldName = name;
    name = n;
    GUI::RenameElement(oldName, name, this);
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
    if(!lastClickState && clicked) {
        return true;
    }
    return false;
}

void GUIElement::SetPressed(bool p) {
    clicked = p;
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

void GUIElement::SetVisibility(bool vis) {
    visible = vis;
}