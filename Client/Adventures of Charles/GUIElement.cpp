#include "Util.h"
#include "GUIElement.h"
#include "GUI.h"

GUIElement::GUIElement() {
    SetName("Name");
    visible = true;
    clickable = false;
    clicked = false;
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

void OnHover() {

}

void OnClick() {

}