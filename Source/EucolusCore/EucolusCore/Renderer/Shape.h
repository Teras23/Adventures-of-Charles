#pragma once

#include <GL/glew.h>
#include "Utility/Utility.h"
#include "Renderer/Renderable.h"

namespace Eucolus
{
	class Shape : public Renderable
	{
	public:
		Shape();
		~Shape();
	};

	class Rect : public Shape
	{
	public:
		Rect();
		Rect(Vector2f position, Vector2f size, Color color);
		~Rect();

		void Render();
		void RenderBorder();
	};
}
