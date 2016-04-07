#include "GUI.h"

std::map<std::string, GUIElement*> GUI::elements;

void GUI::Init() {
    //font = LoadFont("FreeSans.ttf");
    GUIText::font = LoadFont("DroidSans.ttf");

    GUIBox* box = new GUIBox(Vector2i(0, 0), Vector2i(230, 100));
    GUIBox* box2 = new GUIBox(Vector2i(0, 100), Vector2i(100, 100));
    GUIText* text = new GUIText("Test", Vector2i(10, 0));
    text->SetName("Time");

    for(std::map<std::string, GUIElement*>::iterator it = elements.begin(); it != elements.end(); it++) {
        Console::Print(it->first + "  " + it->second->GetName());
    }
}

void GUI::Draw() {
    for(std::map<std::string, GUIElement*>::iterator it = elements.begin(); it != elements.end(); it++) {
        it->second->Draw();
    }
}

void GUI::AddElement(GUIElement* e) {
    if(elements.find(e->GetName()) == elements.end()) {
        elements.insert(std::make_pair(e->GetName(), e));
    }
    else {
        for(int i = 0; i < 100; i++) {
            if(elements.find(e->GetName() + std::to_string(i)) == elements.end()) {
                e->SetName(e->GetName() + std::to_string(i));
                elements.insert(std::make_pair(e->GetName(), e));
                break;
            }
        }
    }
}

GUIElement* GUI::GetElement(std::string name) {
    if(elements.find(name) != elements.end()) {
        return elements.at(name);
    }
    else {
        return NULL;
    }
}

void GUI::RemoveElement(std::string name) {
    elements.erase(name);
}