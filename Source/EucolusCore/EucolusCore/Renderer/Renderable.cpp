#include "Renderer/Renderable.h"

namespace Eucolus
{
	Renderable::Renderable()
	{
	}


	Renderable::~Renderable()
	{
		glDeleteBuffers(1, &m_vbo);
		glDeleteBuffers(1, &m_ibo);
	}

	void Renderable::Render()
	{
		
	}

}