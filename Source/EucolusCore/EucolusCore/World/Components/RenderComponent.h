#pragma once

#include "Utility/Utility.h"
#include "World/Component.h"

namespace Eucolus
{
	class RenderComponent : public Component
	{
	public:
		RenderComponent();
		~RenderComponent();

		void Render();
	};
}
