#include "Utility/Color.h"

namespace Eucolus
{
	Color::Color() :
		m_r(0),
		m_b(0),
		m_g(0),
		m_a(0)
	{
	}

	Color::Color(int r, int b, int g) :
		m_r(r),
		m_b(b),
		m_g(g),
		m_a(255)
	{
	}

	Color::Color(int r, int b, int g, int a) :
		m_r(r),
		m_b(b),
		m_g(g),
		m_a(a)
	{
	}

	Color::~Color()
	{
	}

	//
	//Colorf
	//

	Colorf::Colorf() :
		m_r(1.0f),
		m_b(1.0f),
		m_g(1.0f),
		m_a(1.0f)
	{
	}

	Colorf::Colorf(float r, float b, float g) :
		m_r(r),
		m_b(b),
		m_g(g),
		m_a(1.0f)
	{
	}

	Colorf::Colorf(float r, float b, float g, float a) :
		m_r(r),
		m_b(b),
		m_g(g),
		m_a(a)
	{
	}

	Colorf::~Colorf()
	{
	}

	Colorf ToColorf(Color color)
	{
		return Colorf((float)(color.m_r) / 255.0f,
		              (float)(color.m_b) / 255.0f,
		              (float)(color.m_g) / 255.0f,
		              (float)(color.m_a) / 255.0f);
	}
}
