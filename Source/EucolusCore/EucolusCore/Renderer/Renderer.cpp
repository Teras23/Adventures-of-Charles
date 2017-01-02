#include "Renderer/Renderer.h"
#include "Renderer/Shape.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "Game.h"

namespace Eucolus {

	std::shared_ptr<Renderer> Renderer::_rendererSingleton = nullptr;

	Renderer::Renderer()
	{
		Console::Print("Renderer Created");
    }

    Renderer::~Renderer() {
		SDL_GL_DeleteContext(m_glContext);
    }

    bool Renderer::Init() {
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

		SDL_Window* sdlWindow = Window::GetWindow()->GetSDLWindow();

		if(sdlWindow == nullptr)
		{
			Console::PrintError("Could not get SDL Window");
			return true;
		}

		SDL_GLContext context = SDL_GL_CreateContext(sdlWindow);

    	m_glContext = context;

		if(context == nullptr) {
			Console::PrintError("Could not create OpenGL context");
			return true;
		}

		GLenum glewError = glewInit();

		if(glewError != GLEW_OK) {
			Console::PrintError("GLEW init error " + std::to_string(glewError));
			return true;
		}

		if(InitGL()) {
			Console::PrintError("Error initing OpenGL");
		}

		Console::Print("Game initialization complete!");

		return false;
    }

	std::shared_ptr<Renderer> Renderer::GetRenderer()
	{
		if(_rendererSingleton == nullptr)
		{
			std::make_shared<Renderer>();
		}

		return _rendererSingleton;
	}

	bool Renderer::InitGL() {
		glClearColor(0.0f, 1.0f, 1.0f, 0.0f);
		glClearDepth(1.0f);

		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

		glCreateProgram();

		m_shaders.push_back(std::make_shared<Shader>("Resources/Shaders/textureShading"));
		return false;
	}

    void Renderer::Render() {
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);		

		m_shaders[0]->Bind();

		Rect rect = Rect(Vector2f(0, 0), Vector2f(32, 32), Color(255, 0, 255, 255));
		Texture texture = Texture("Resources/Textures/player.png");
		texture.Render();
		rect.Render();

		SDL_GL_SwapWindow(Game::GetGame()->m_window->GetSDLWindow());
    }

    bool Renderer::Quit() {
		return false;
    }

	void Renderer::DrawTexture(Vector2f position, Vector2f size, Texture texture) {

	}

	void Renderer::DrawRect(Vector2f position, Vector2f size, Color color) {

	}
}
