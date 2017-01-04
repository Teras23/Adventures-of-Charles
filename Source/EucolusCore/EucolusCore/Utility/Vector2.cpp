#include "Utility/Vector2.h"

namespace Eucolus
{
	Vector2f::Vector2f() :
		m_x(0),
		m_y(0)
	{
	}

	Vector2f::Vector2f(float x, float y) :
		m_x(x),
		m_y(y)
	{
	}

	Vector2f::~Vector2f()
	{
	}

	Vector2f Vector2f::operator+=(Vector2f second)
	{
		m_x += second.m_x;
		m_y += second.m_y;
		return *this;
	}
}
