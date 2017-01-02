#ifndef WINDOW_H
#define WINDOW_H

#include "Utility\Utility.h"

#include <SDL.h>
#include <memory>
#include <string>

namespace Eucolus {
    class Window {
    public:
        Window(std::string windowName, Vector2f windowPosition, Vector2f windowSize);
        ~Window();

		SDL_Window* GetSDLWindow();

    private:
		SDL_Window* m_sdlWindow = nullptr;
    };
}

#endif