#pragma once

#include "Renderer/Renderer.h"
#include "Utility/Utility.h"

#include <vector>

namespace Eucolus
{
	namespace GUI
	{
		class Element
		{
		public:
			Element();
			~Element();

			virtual void Update();
			virtual void Render();

		private:
			bool m_isVisible;
			Vector2f m_position;
		};
	}
}
