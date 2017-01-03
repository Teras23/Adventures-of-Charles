#pragma once

#include "Utility/Utility.h"

namespace Eucolus
{
	class Vertex
	{
	public:
		Vertex();
		Vertex(Vector2f position, Colorf color, Vector2f textureCoords);
		~Vertex();

		Vector2f m_position;
		Colorf m_color;
		Vector2f m_textureCoords;
	};
}
