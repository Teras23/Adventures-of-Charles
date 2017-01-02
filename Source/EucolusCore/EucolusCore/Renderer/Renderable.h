#pragma once

#include <GL/glew.h>

namespace Eucolus {
	class Renderable
	{
	public:
		Renderable();
		~Renderable();

		virtual void Render();
	protected:
		GLuint vbo, ibo;
	};
}