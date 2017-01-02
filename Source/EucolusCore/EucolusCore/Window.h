#pragma once

#include "Utility/Utility.h"

#include <SDL.h>
#include <memory>

namespace Eucolus
{
	class Window
	{
	public:
		Window();
		~Window();

		void Init(std::string windowName, Vector2f windowPosition, Vector2f windowSize);

		SDL_Window* GetSDLWindow();

		static std::shared_ptr<Window> GetWindow();
	private:
		SDL_Window* m_sdlWindow = nullptr;

		static std::shared_ptr<Window> _windowSingleton;
	};
}
