#pragma once

#include "GameObject.h"
#include "Component.h"

#include <vector>
#include <memory>

namespace Eucolus
{
	class Entity : public GameObject
	{
	public:
		Entity();
		~Entity();

		bool Init();
		void Update();

	private:
		
	};
}
