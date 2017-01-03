#include "Utility/Vertex.h"

namespace Eucolus
{
	Vertex::Vertex() :
		m_position(Vector2f()),
		m_color(Colorf()),
		m_textureCoords(Vector2f())
	{
	}

	Vertex::Vertex(Vector2f position, Colorf color, Vector2f textureCoords) :
		m_position(position),
		m_color(color),
		m_textureCoords(textureCoords)
	{
	}

	Vertex::~Vertex()
	{
	}
}
