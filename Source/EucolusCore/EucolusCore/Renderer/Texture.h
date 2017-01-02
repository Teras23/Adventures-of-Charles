#pragma once

#include "Utility/Utility.h"
#include "Renderer/Shape.h"

#include <GL/glew.h>

namespace Eucolus
{
	class Texture : public Renderable
	{
	public:
		Texture(std::string path);
		~Texture();

		void Render();

	private:
		GLuint m_texture;
	};
}
