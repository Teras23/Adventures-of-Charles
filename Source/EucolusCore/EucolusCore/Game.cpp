#include "Game.h"
#include <iostream>
#include <SDL_image.h>

namespace Eucolus
{
	std::shared_ptr<Game> Game::_gameSingleton = nullptr;

	Game::Game() :
		m_renderer(nullptr),
		m_window(nullptr),
		m_gameState(nullptr)
	{
		Console::Print("Game Created");
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

		m_window = Window::GetWindow();
		m_window->Init(windowName, windowPosition, windowSize);
		m_renderer = Renderer::GetRenderer();
		m_renderer->Init();

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

			Update();

			m_renderer->Render();
			SDL_Delay(1);
		}
		Quit();
	}

	void Game::Update()
	{
	}

	bool Game::Quit()
	{
		Console::Print("Game closed normally!");
		SDL_Quit();
		return false;
	}

	std::shared_ptr<Game> Game::GetGame()
	{
		if(_gameSingleton == nullptr)
		{
			_gameSingleton = std::make_shared<Game>();
		}
		return _gameSingleton;
	}
}
