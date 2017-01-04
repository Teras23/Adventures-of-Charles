#pragma once

#include "Utility/Utility.h"
#include "World/Component.h"
#include "Collision/Collider.h"

namespace Eucolus
{
	class CollisionComponent : public Component
	{
	public:
		CollisionComponent();
		~CollisionComponent();

		Collider m_collider;
	};
}
