#include "Window.h"

namespace Eucolus
{
	std::shared_ptr<Window> Window::_windowSingleton;

	Window::Window()
	{
		Console::Print("Window Created");
	}

	Window::~Window()
	{
		SDL_DestroyWindow(m_sdlWindow);
	}

	void Window::Init(std::string windowName, Vector2f windowPosition, Vector2f windowSize)
	{
		m_sdlWindow = SDL_CreateWindow(
			windowName.c_str(),
			static_cast<int>(windowPosition.m_x),
			static_cast<int>(windowPosition.m_y),
			static_cast<int>(windowSize.m_x),
			static_cast<int>(windowSize.m_y),
			SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);

		Console::Print("Window initialization complete!");
	}


	SDL_Window* Window::GetSDLWindow()
	{
		return m_sdlWindow;
	}

	std::shared_ptr<Window> Window::GetWindow()
	{
		if(_windowSingleton == nullptr)
		{
			_windowSingleton = std::make_shared<Window>();
		}
		return _windowSingleton;
	}
}
