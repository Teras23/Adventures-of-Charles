#pragma once

#include "Utility/Utility.h"
#include "Collision/Collider.h"
#include "Collision/BoxCollider.h"

namespace Eucolus
{
	class Collision
	{
	public:
		static void CollisionUpdate();
		static bool BroadAABBCollision(BoxCollider, BoxCollider);
		static bool AABBCollision(BoxCollider, BoxCollider);
		static float SweptCollision(BoxCollider, BoxCollider);

		static void AddCollider(std::shared_ptr<Collider>);
		static void RemoveCollider(std::shared_ptr<Collider>);

	private:
		static std::vector<std::shared_ptr<Collider>> _colliders;
	};
}
