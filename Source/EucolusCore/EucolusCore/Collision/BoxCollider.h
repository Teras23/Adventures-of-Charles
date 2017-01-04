#pragma once

#include "Utility/Utility.h"
#include "Collision/Collider.h"

namespace Eucolus
{
	class BoxCollider : public Collider
	{
	public:
		BoxCollider();
		BoxCollider(Vector2f, Vector2f, Vector2f);
		~BoxCollider();

		Vector2f m_position;
		Vector2f m_size;
		Vector2f m_velocity;
	};
}