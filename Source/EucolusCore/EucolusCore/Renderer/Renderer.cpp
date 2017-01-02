#include "Renderer/Renderer.h"
#include "Renderer/Shape.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

namespace Eucolus
{
	Renderer::Renderer(std::shared_ptr<Window> window) :
		m_window(window)
	{
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
	}

	Renderer::~Renderer()
	{
		SDL_GL_DeleteContext(m_glContext);
	}

	bool Renderer::Init()
	{
		m_glContext = SDL_GL_CreateContext(m_window->GetSDLWindow());

		if (m_glContext == nullptr)
		{
			Console::PrintError("Could not create OpenGL context");
			return true;
		}

		GLenum glewError = glewInit();

		if (glewError != GLEW_OK)
		{
			Console::PrintError("GLEW init error");
			return true;
		}

		if (InitGL())
		{
			Console::PrintError("Error initing OpenGL");
		}

		return false;
	}

	bool Renderer::InitGL()
	{
		glClearColor(0.0f, 1.0f, 1.0f, 0.0f);
		glClearDepth(1.0f);

		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

		glCreateProgram();

		m_shaders.push_back(std::make_shared<Shader>("Resources/Shaders/textureShading"));
		return false;
	}

	void Renderer::Render()
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		m_shaders[0]->Bind();

		Rect rect = Rect(Vector2f(0, 0), Vector2f(128, 128), Color(255, 0, 255, 255));
		Texture texture = Texture("Resources/Textures/player.png");
		texture.Render();
		rect.Render();

		SDL_GL_SwapWindow(m_window->GetSDLWindow());
	}

	bool Renderer::Quit()
	{
		return false;
	}

	void Renderer::DrawTexture(Vector2f position, Vector2f size, Texture texture)
	{
	}

	void Renderer::DrawRect(Vector2f position, Vector2f size, Color color)
	{
	}
}
