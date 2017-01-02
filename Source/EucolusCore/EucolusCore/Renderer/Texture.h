#pragma once

#include "Utility/Utility.h"
#include "Renderer/Shape.h"

#include <GL/glew.h>

namespace Eucolus
{
	class Texture : public Rect
	{
	public:
		Texture(std::string path, Vector2f, Vector2f, Vector2f);
		~Texture();

		void Render(Vector2f);

	private:
		GLuint m_texture;
		int m_height, m_width;
	};
}
