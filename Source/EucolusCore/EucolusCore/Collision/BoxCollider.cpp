#include "Collision/BoxCollider.h"

namespace Eucolus
{
	BoxCollider::BoxCollider()
	{
		m_position = Vector2f();
		m_size = Vector2f();
		m_velocity = Vector2f();
	}

	BoxCollider::BoxCollider(Vector2f position, Vector2f size, Vector2f velocity) :
	m_position(position),
	m_size(size),
	m_velocity(velocity)
	{
		
	}


	BoxCollider::~BoxCollider()
	{
		
	}

}