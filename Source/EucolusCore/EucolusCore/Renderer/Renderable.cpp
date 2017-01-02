#include "Renderer/Renderable.h"

namespace Eucolus
{
	Renderable::Renderable()
	{
	}


	Renderable::~Renderable()
	{
		glDeleteBuffers(1, &vbo);
		glDeleteBuffers(1, &ibo);
	}

	void Renderable::Render()
	{
		
	}

}