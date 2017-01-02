#pragma once

#include "Window.h"
#include "Renderer/Shader.h"

#include <SDL.h>
#include <GL/glew.h>

#include <memory>
#include <vector>

namespace Eucolus
{
	class Renderer
	{
	public:
		Renderer(std::shared_ptr<Window> window);
		~Renderer();

		bool Init();
		void Render();
		bool Quit();

		void DrawRect(Vector2f position, Vector2f size, Color color);
		void DrawRectBorder(Vector2f position, Vector2f size, Color color); //Border width
		void DrawLine(Vector2f origin, Vector2f destination, Color color); //Line width
		void DrawText(Vector2f origin, std::string text); //Text size, font

		static std::vector<std::shared_ptr<Shader>> GetShaders();

	private:
		bool InitGL();

		static std::vector<std::shared_ptr<Shader>> _shaders;

		SDL_GLContext m_glContext;
		std::shared_ptr<Window> m_window;
	};
}