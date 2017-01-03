#pragma once

#include "Utility/Utility.h"
#include "GUI/GUIElement.h"

namespace Eucolus
{
	namespace GUI
	{
		class Button : Element
		{
		public:
			Button();
			~Button();

			void Update();
			void Render();

		private:
		};
	}
}
