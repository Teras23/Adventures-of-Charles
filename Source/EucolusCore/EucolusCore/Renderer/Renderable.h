#pragma once

#include <GL/glew.h>
#include "Renderer/Shader.h"
#include "Utility/Utility.h"
#include <memory>

namespace Eucolus {
	class Renderable
	{
	public:
		Renderable();
		~Renderable();

		virtual void Render();
	protected:
		GLuint m_vbo, m_ibo;
		std::shared_ptr<Shader> m_shader;
	};
}
