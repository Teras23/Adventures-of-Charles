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

	class DrawableRect : public Shape
	{
	public:
		DrawableRect();
		DrawableRect(Vector2f position, Vector2f size, Color color);
		~DrawableRect();

		void Render();
		void RenderBorder();
	};
}
