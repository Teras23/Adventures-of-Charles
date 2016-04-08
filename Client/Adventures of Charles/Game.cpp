#include <SDL_ttf.h>
#include <SDL_image.h>
#include <iostream>
#include "GUI.h"
#include "Game.h"
#include "World.h"
#include "Input.h"
#include "Network.h"

const int FRAMERATE = 300;

bool Game::running = false;
bool Game::onlineMode = false;
SDL_Window* Game::window = NULL;
SDL_Surface* Game::screen = NULL;
SDL_Renderer* Game::renderer = NULL;
SDL_Event Game::sdlEvent;
float Game::deltaTime;

std::map<std::string, SDL_Texture*> Game::textures;

int Game::Init() {
    //Initialize 
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        std::cout << "Could not init SDL" << std::endl;
        return -1;
    }
    else {
        window = SDL_CreateWindow("AOC", 400, 400, 800, 600, SDL_WINDOW_SHOWN);
        //screen = SDL_GetWindowSurface(window);
    }

    //Initialize SDL_net
    if(SDLNet_Init() < 0) {
        std::cout << "Could not init SDL_net " << SDLNet_GetError() << std::endl;
        return -1;
    }

    //Create Renderer
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if(renderer == NULL) {
        std::cout << "Could not create renderer " << SDL_GetError() << std::endl;
        return -1;
    }

    //Initialize SDL_image
    if(!IMG_Init(IMG_INIT_PNG)) {
        std::cout << "Could not init SDL_image " << IMG_GetError() << std::endl;
        return -1;
    }

    //Initialize SDL_ttf
    if(TTF_Init() == -1) {
        std::cout << "Could not init SDL_ttf" << TTF_GetError() << std::endl;
        return -1;
    }

    //Loading files
    textures["PlayerTexture"] = LoadTexture("Textures/player.png");
    textures["SolderTexture"] = LoadTexture("Textures/solder.png");
    GUIBox::texture = LoadTexture("Textures/GUI/Box.png");
    GUIButton::texture = LoadTexture("Textures/GUI/Box.png");

    //Other initialization
    SDL_SetRenderDrawColor(renderer, 0x00, 0xFF, 0xFF, 0xFF);
    running = true;
    GUI::Init();
    World::Init();
    std::cout << "Game initialized" << std::endl;

    if(onlineMode) {
        std::string ip = "192.168.1.79";
        //ip = "127.0.0.1";
        Network::Connect(ip, 1234);
    }
    return 0;
}

int Game::Quit() {
    std::cout << "Qutting game normally" << std::endl;
    Network::Disconnect();
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

void Game::Loop() {
    int lastTime = SDL_GetTicks();
    deltaTime = 0.02f;
    while(running) {
        int startTime = SDL_GetTicks();
        int frameTime = startTime - lastTime;
        if(frameTime >= 16) {
            Network::ReceiveMessage();

            Input();

            //Logic
            World::Update();

            deltaTime = frameTime / 60.0f;
            lastTime = startTime;
        }
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

void Game::Render() {
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0xFF, 0xFF);

    if(GUI::GetElement("Time") != NULL) {
        GUI::GetElement("Time")->SetText("Ticks: " + std::to_string(SDL_GetTicks()) + " DeltaTime: " + std::to_string(deltaTime));
    }

    if(GUI::GetElement("TestButton") != NULL) {
        if(GUI::GetElement("TestButton")->IsPressed()) {
            Console::Print("Button Press");
        }
    }

    World::Draw();
    GUI::Draw();
    
    SDL_SetRenderDrawColor(renderer, 0x00, 0xFF, 0xFF, 0xFF);
    SDL_RenderPresent(renderer);
}