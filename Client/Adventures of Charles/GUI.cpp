#include "GUI.h"

std::map<std::string, GUIElement*> GUI::elements;
std::vector<std::string> GUI::elementOrder;
GUIElement* GUI::clickedElement;

void GUI::Init() {
    //font = LoadFont("FreeSans.ttf");
    GUIText::font = LoadFont("DroidSans.ttf");

    GUIBox* box = new GUIBox(Vector2i(0, 0), Vector2i(230, 100));
    GUIBox* box2 = new GUIBox(Vector2i(0, 100), Vector2i(100, 100));
    GUIText* text = new GUIText("Test", Vector2i(10, 0));
    text->SetName("Time");

    GUIButton* button = new GUIButton("Test", Vector2i(200, 20), Vector2i(50, 20));
    button->SetName("TestButton");

    for(std::map<std::string, GUIElement*>::iterator it = elements.begin(); it != elements.end(); it++) {
        Console::Print(it->first + "  " + it->second->GetName());
    }
}

void GUI::Draw() {
    for(int i = 0; i < elementOrder.size(); i++) {
        elements[elementOrder[i]]->Draw();
    }
    /*for(std::map<std::string, GUIElement*>::iterator it = elements.begin(); it != elements.end(); it++) {
        it->second->Draw();
    }*/
}

void GUI::Update() {
    if(clickedElement != NULL) {
        clickedElement->Update();
    }
}





//
//  Element Functions
//
void GUI::AddElement(GUIElement* e) {
    if(elements.find(e->GetName()) == elements.end()) {     //If elements map does not have that element
        elements.insert(std::make_pair(e->GetName(), e));
        elementOrder.push_back(e->GetName());
    }
    else {                                                  //If elements map does have the element, try to add a number to the end
        for(int i = 0; i < 100; i++) {
            if(elements.find(e->GetName() + std::to_string(i)) == elements.end()) {
                e->SetName(e->GetName() + std::to_string(i));
                //No need to change elements here, done with GUIElement setname function
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
    if(elements.find(name) != elements.end()) {
        elements.erase(name);
        elementOrder.erase(find(elementOrder.begin(), elementOrder.end(), name));
    }
}

void GUI::RenameElement(std::string oldName, std::string newName, GUIElement* element) {
    RemoveElement(oldName);
    AddElement(element);
}




GUIElement* GUI::GetElementUnderMouse() {
    Vector2i mousePos = Vector2i();
    SDL_GetMouseState(&mousePos.x, &mousePos.y);
    for(int i = elementOrder.size() - 1; i >= 0; i--) {
        GUIElement* pressedElement = elements[elementOrder[i]];
        if(mousePos.x > pressedElement->GetPosition().x &&
        mousePos.y > pressedElement->GetPosition().y &&
        mousePos.x < pressedElement->GetPosition().x + pressedElement->GetSize().x &&
        mousePos.y < pressedElement->GetPosition().y + pressedElement->GetSize().y) {
            
            return pressedElement;
        }
    }
    return NULL;
}

bool GUI::MouseEvent(SDL_Event e) {
    Vector2i mousePos = Vector2i();
    SDL_GetMouseState(&mousePos.x, &mousePos.y);
    GUIElement* pressedElement = GetElementUnderMouse();

    switch(e.type) {
    case SDL_MOUSEBUTTONDOWN:
        Console::Print("Press " + std::to_string(mousePos.x) + " " + std::to_string(mousePos.y));
        if(pressedElement != NULL) {
            clickedElement = pressedElement;
            pressedElement->SetPressed(true);
            Console::Print(pressedElement->GetName());
            return true;
        }
        break;
    case SDL_MOUSEBUTTONUP:
        if(clickedElement != NULL) {
            clickedElement->SetPressed(false);
        }
        return true;
    case SDL_MOUSEMOTION:

        return false;
    }
    return false;
}