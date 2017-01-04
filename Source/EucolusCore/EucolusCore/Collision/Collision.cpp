#include "Collision/Collision.h"

namespace Eucolus
{
	std::vector<std::shared_ptr<Collider>> Collision::_colliders;

	void Collision::CollisionUpdate()
	{
		for(auto i = 0; i < _colliders.size(); i++)
		{
			for(auto j = i; j < _colliders.size(); j++)
			{
				
			}
		}
	}

	bool Collision::BroadAABBCollision(BoxCollider box1, BoxCollider box2)
	{
		return false;
	}

	bool Collision::AABBCollision(BoxCollider box1, BoxCollider box2)
	{
		box1.m_position += box1.m_velocity;
		box2.m_position += box2.m_velocity;

		if(box1.m_position.m_x < box2.m_position.m_x + box2.m_size.m_x &&
			box1.m_position.m_x + box1.m_size.m_x > box2.m_position.m_x &&
			box1.m_position.m_y < box2.m_position.m_y + box2.m_size.m_y &&
			box1.m_position.m_y + box1.m_size.m_y > box2.m_position.m_y)
		{
			return true;
		}

		return false;
	}

	float Collision::SweptCollision(BoxCollider box1, BoxCollider box2)
	{
		return 0.0f;
	}

	void Collision::AddCollider(std::shared_ptr<Collider> collider)
	{
		_colliders.push_back(collider);
	}

	void Collision::RemoveCollider(std::shared_ptr<Collider> collider)
	{
		for(auto i = 0; i < _colliders.size(); i++)
		{
			if(_colliders[i] == collider)
			{
				_colliders.erase(_colliders.begin() + i);
			}
		}
	}
}
