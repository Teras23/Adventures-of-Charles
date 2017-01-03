#include "Renderer/Texture.h"
#include <SDL_image.h>
#include "Renderer/Renderer.h"

namespace Eucolus
{
	Texture::Texture(std::string path, Vector2f position, Vector2f size, Vector2f origin)
	{
		SDL_Surface* sdlSurface = IMG_Load(path.c_str());

		if (sdlSurface == nullptr)
		{
			Console::PrintError("Could not load image: " + path);
		}

		m_width = sdlSurface->w;
		m_height = sdlSurface->h;

		glGenTextures(1, &m_texture);
		glBindTexture(GL_TEXTURE_2D, m_texture);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, sdlSurface->w, sdlSurface->h, 0, GL_RGBA, GL_UNSIGNED_BYTE, sdlSurface->pixels);

		SDL_FreeSurface(sdlSurface);

		auto fillColor = Colorf(1.0f, 1.0f, 1.0f, 1.0f);

		Vertex vertices[] = {
			Vertex(Vector2f(position.m_x,				position.m_y),				fillColor, Vector2f(0.0f,					0.0f)), //Top left
			Vertex(Vector2f(position.m_x + size.m_x,	position.m_y),				fillColor, Vector2f(origin.m_x / m_width,	0.0f)), //Top right
			Vertex(Vector2f(position.m_x + size.m_x,	position.m_y + size.m_y),	fillColor, Vector2f(origin.m_x / m_width,	origin.m_y / m_height)), //Bottom right
			Vertex(Vector2f(position.m_x,				position.m_y + size.m_y),	fillColor, Vector2f(0.0f,					origin.m_y / m_height)) //Bottom left
		};

		glGenBuffers(1, &m_vbo);
		glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

		Vector3ui indexes[] = {
			Vector3ui(0, 1, 2),
			Vector3ui(2, 3, 0)
		};

		glGenBuffers(1, &m_ibo);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ibo);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indexes), indexes, GL_STATIC_DRAW);

		m_shader = Renderer::GetShaders()[0];
	}

	Texture::~Texture()
	{
		glDeleteTextures(1, &m_texture);
	}

	void Texture::Render(Vector2f position)
	{
		m_shader->Bind(position);

		//Binding
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, m_texture);

		glBindBuffer(GL_ARRAY_BUFFER, m_vbo);

		//Position - 0
		glEnableVertexAttribArray(0);

		glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), 0); //8 values in vertex

		//Color - 1
		glEnableVertexAttribArray(1);
		glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(2 * sizeof(float))); //pointer to offset

		//TextureCoords - 2
		glEnableVertexAttribArray(2);
		glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float))); //pointer to offset

		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0); //Actually signed int

		glBindBuffer(GL_ARRAY_BUFFER, 0);

		glBindTexture(GL_TEXTURE_2D, 0);
	}
}
