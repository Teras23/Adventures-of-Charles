#include "Utility/Vector3.h"

namespace Eucolus
{
	Vector3f::Vector3f() :
		m_x(0),
		m_y(0),
		m_z(0)
	{
	}

	Vector3f::Vector3f(float x, float y, float z) :
		m_x(x),
		m_y(y),
		m_z(z)
	{
	}

	Vector3f::~Vector3f()
	{
	}

	//
	//
	//

	Vector3i::Vector3i() :
		m_x(0),
		m_y(0),
		m_z(0)
	{
	}

	Vector3i::Vector3i(int x, int y, int z) :
		m_x(x),
		m_y(y),
		m_z(z)
	{
	}

	Vector3i::~Vector3i()
	{
	}

	//
	//
	//

	Vector3ui::Vector3ui() :
		m_x(0),
		m_y(0),
		m_z(0)
	{
	}

	Vector3ui::Vector3ui(unsigned int x, unsigned int y, unsigned int z) :
		m_x(x),
		m_y(y),
		m_z(z)
	{
	}

	Vector3ui::~Vector3ui()
	{
	}
}
