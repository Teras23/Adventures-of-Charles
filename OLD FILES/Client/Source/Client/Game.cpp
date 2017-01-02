#include <SDL_ttf.h>
#include <SDL_image.h>
#include <iostream>
#include "GUI.h"
#include "Game.h"
#include "Input.h"
#include "Network.h"
#include "MenuEditor.h"
#include "Renderer.h"
#include "../Shared/World.h"
#include "../Shared/Util.h"

const int FRAMERATE = 300;

bool Game::running = false;
bool Game::onlineMode = false;
SDL_Window* Game::window = NULL;
SDL_Surface* Game::screen = NULL;
SDL_Renderer* Game::renderer = NULL;
SDL_Event Game::sdlEvent;
Vector2i Game::screenSize;
double Game::deltaTime;
double Game::interpolation;
std::string Game::serverIp = "127.0.0.1";

std::map<std::string, SDL_Texture*> Game::textures;

int Game::Init() {
    //Initialize 
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        Console::PrintError("Could not init SDL", SDL_GetError());
        return -1;
    }
    else {
        window = SDL_CreateWindow("AOC", 400, 200, 1024, 768, SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);
        //screen = SDL_GetWindowSurface(window);
    }

    Renderer::context = SDL_GL_CreateContext(window);
    if(Renderer::context == NULL) {
        Console::PrintError("Could not create OpenGL context", SDL_GetError());
        return -1;
    }
    else {
        Renderer::Init();
    }

    //Initialize SDL_net
    if(SDLNet_Init() < 0) {
        Console::PrintError("Could not init SDL_net", SDLNet_GetError());
        return -1;
    }

    //Create Renderer
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if(renderer == NULL) {
        Console::PrintError("Could not create renderer", SDL_GetError());
        return -1;
    }

    //Initialize SDL_image
    if(!IMG_Init(IMG_INIT_PNG)) {
        Console::PrintError("Could not init SDL_image", IMG_GetError());
        return -1;
    }

    //Initialize SDL_ttf
    if(TTF_Init() == -1) {
        Console::PrintError("Could not init SDL_ttf", TTF_GetError());
        return -1;
    }

    //Loading files
    textures["PlayerTexture"] = LoadTexture("Resources/Textures/player.png");
    textures["SolderTexture"] = LoadTexture("Resources/Textures/solder.png");
    textures["Tilemap"] = LoadTexture("Resources/Textures/tilemap.png");
    textures["ButtonTexture"] = LoadTexture("Resources/Textures/GUI/Button.png");
    textures["ButtonHoverTexture"] = LoadTexture("Resources/Textures/GUI/Button.png");
    textures["ButtonPressTexture"] = LoadTexture("Resources/Textures/GUI/Button.png");
    textures["BoxTexture"] = LoadTexture("Resources/Textures/GUI/Box.png");

    //Other initialization
    screenSize = Vector2i(0, 0);
    SDL_GetWindowSize(window, &screenSize.x, &screenSize.y);
    //SDL_SetRenderDrawColor(renderer, 0x00, 0xFF, 0xFF, 0xFF);
    running = true;
    GUI::Init();
    World::Init();
    Console::Print("Game initialized");

    SDL_SetRenderDrawColor(renderer, 0x00, 0xFF, 0xFF, 0xFF);

    if(onlineMode) {
        Console::Print("Running online");
        //serverIp = "192.168.1.79";
        Network::Connect(serverIp, 1234);
    }
    else {
        Console::Print("Running offline");
    }
    return 0;
}

int Game::Quit() {
    Console::Print("Qutting game normally");
    Network::Disconnect();
    SDL_GL_DeleteContext(Renderer::context);
    SDL_DestroyRenderer(renderer);
    renderer = NULL;
    SDL_DestroyWindow(window);
    window = NULL;

    SDLNet_Quit();
    TTF_Quit();
    IMG_Quit();
    SDL_Quit();
    return 0;
}

#define UPDATETIME 1000.0 / 60.0

void Game::Loop() {
    double lastTime = SDL_GetTicks();
    deltaTime = 0.1;
    //deltaTime = UPDATETIME;
    double lag = 0.0;

    while(running) {
        double currentTime = SDL_GetTicks();
        double frameTime = currentTime - lastTime;
        lastTime = currentTime;

        lag += frameTime;

        while(lag >= UPDATETIME) {
            Network::ReceiveMessage();
            //Console::Print(std::to_string(frameTime));
            Input();

            //Logic
            Update();

            //deltaTime = frameTime / 1000.0;
            
            lag -= UPDATETIME;
        }

        interpolation = lag / UPDATETIME;

        //state ? now * interpolation + last * (1.0 - interpolation)
        //Console::Print(std::to_string(interpolation));
        //interpelation for between state

        //Renderer::Render();
        Render();
        SDL_Delay(1);
    }
    Quit();
}

void Game::Input() {
    while(SDL_PollEvent(&sdlEvent) != 0) {
        switch(sdlEvent.type) {
        case SDL_QUIT:
            running = false;
            break;
        case SDL_KEYDOWN:
            switch(sdlEvent.key.keysym.sym) {
            case SDLK_w:
                Input::WPressed = true;
                break;
            case SDLK_s:
                Input::SPressed = true;
                break;
            case SDLK_d:
                Input::DPressed = true;
                break;
            case SDLK_a:
                Input::APressed = true;
                break;
            }
            break;
        case SDL_KEYUP:
            switch(sdlEvent.key.keysym.sym)
            {
            case SDLK_w:
                Input::WPressed = false;
                break;
            case SDLK_s:
                Input::SPressed = false;
                break;
            case SDLK_d:
                Input::DPressed = false;
                break;
            case SDLK_a:
                Input::APressed = false;
                break;
            case SDLK_PAGEUP:
                World::AddEnemy();
                break;
            case SDLK_PAGEDOWN:
                World::RemoveLastEnemy();
                break;
            }
            break;
        case SDL_MOUSEBUTTONDOWN:
            if(!GUI::MouseEvent(sdlEvent)) {
                Vector2i mousePos = Vector2i();
                SDL_GetMouseState(&mousePos.x, &mousePos.y);
                mousePos = World::GetGameMousePosition(mousePos);
                Console::Print("Clicked on " + std::to_string(mousePos.x / 32) + " " + std::to_string(mousePos.y / 32));
                MenuEditor::EditTile(Vector2i(mousePos.x / 32, mousePos.y / 32));
                //Not clicked on gui
            }
            break;
        case SDL_MOUSEBUTTONUP:
            if(!GUI::MouseEvent(sdlEvent)) {
                //Not clicked on gui
            }
            break;
        case SDL_MOUSEMOTION:
            if(!GUI::MouseEvent(sdlEvent)) {
                //Not hover on gui
            }
            break;
        }
    }
}

void Game::Update() {
    if(GUI::GetElement("TestButton") != NULL) {
        if(GUI::GetElement("TestButton")->IsPressed()) {
            Console::Print("Button Press");
            SaveMap();
        }
    }

    if(GUI::GetElement("TestButton2") != NULL) {
        if(GUI::GetElement("TestButton2")->IsPressed()) {
            LoadMap();
        }
    }

    if(GUI::GetElement("NextTexture") != NULL) {
        if(GUI::GetElement("NextTexture")->IsPressed()) {
            MenuEditor::NextTile();
        }
    }

    if(GUI::GetElement("PrevTexture") != NULL) {
        if(GUI::GetElement("PrevTexture")->IsPressed()) {
            MenuEditor::PrevTile();
        }
    }

    if(GUI::GetElement("PrevLayer") != NULL) {
        if(GUI::GetElement("PrevLayer")->IsPressed()) {
            MenuEditor::PrevLayer();
        }
    }

    if(GUI::GetElement("NextLayer") != NULL) {
        if(GUI::GetElement("NextLayer")->IsPressed()) {
            MenuEditor::NextLayer();
        }
    }

    GUI::Update();
    World::Update();
}

void Game::Render() {
    SDL_RenderClear(renderer);

    if(GUI::GetElement("Time") != NULL) {
        GUI::GetElement("Time")->SetText("Ticks: " + std::to_string(SDL_GetTicks()) + " DeltaTime: " + std::to_string(deltaTime));
    }

    if(GUI::GetElement("Mouse") != NULL) {
        Vector2i mousePos = Vector2i();
        SDL_GetMouseState(&mousePos.x, &mousePos.y);
        GUI::GetElement("Mouse")->SetText("Mouse Position: " + std::to_string(mousePos.x) + ", " + std::to_string(mousePos.y)
            + "\nGame Mouse Position: " + std::to_string(World::GetGameMousePosition(mousePos).x) +", " + std::to_string(World::GetGameMousePosition(mousePos).y));
    }

    World::Draw();
    GUI::Draw();

    SDL_RenderPresent(renderer);
}