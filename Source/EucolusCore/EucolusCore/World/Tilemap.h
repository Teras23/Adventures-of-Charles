#pragma once

#include "GameObject.h"

namespace Eucolus
{
	class Tilemap : GameObject
	{
	public:
		Tilemap();
		~Tilemap();

		virtual bool Init();
		virtual void Update();
	};
}
