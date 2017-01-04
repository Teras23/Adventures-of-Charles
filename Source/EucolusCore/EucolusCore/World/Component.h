#pragma once

#include "Utility/Utility.h"

namespace Eucolus
{
	class GameObject;

	class Component
	{
	public:
		Component();
		~Component();

		virtual bool Init();
		virtual void Update();
		virtual void Render();

		GameObject *m_parent;
	};
}
