#include <iostream>
#include <SDL_image.h>
#include "Game.h"
#include "Utility/Utility.h"
#include "Collision/Collision.h"

namespace Eucolus
{
	Game::Game() :
		m_renderer(nullptr),
		m_window(nullptr),
		m_gameState(nullptr)
	{
	}

	Game::~Game()
	{
	}

	bool Game::Init(std::string windowName, Vector2f windowPosition, Vector2f windowSize)
	{
		m_isRunning = true;

		if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
		{
			Console::PrintError("Could not init SDL");
			//Console::PrintError("Could not init SDL", SDL_GetError());
			return true;
		}

		if (!IMG_Init(IMG_INIT_PNG))
		{
			Console::PrintError("Could not init SDL_image");

			return true;
		}

		m_window = std::make_shared<Window>(windowName, windowPosition, windowSize);
		m_renderer = std::make_shared<Renderer>(m_window);

		m_renderer->Init();

		m_world = std::make_shared<World>();

		Console::Print("Game initialization complete!");

		return false;
	}

	void Game::Run()
	{
		while (m_isRunning)
		{
			SDL_Event evt;

			while (SDL_PollEvent(&evt) != 0)
			{
				switch (evt.type)
				{
				case SDL_QUIT:
					m_isRunning = false;
					break;
				}
			}

			//Get Input

			Update();
			Collision::CollisionUpdate();

			Render();

			SDL_Delay(1);
		}
		Quit();
	}

	void Game::Update()
	{
		m_world->Update();
	}

	void Game::Render()
	{
		m_renderer->StartRender();

		m_world->Render();

		//Render GUI

		m_renderer->EndRender();
	}


	bool Game::Quit()
	{
		Console::Print("Game closed normally!");
		SDL_Quit();
		return false;
	}
}
