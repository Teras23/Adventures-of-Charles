#pragma once

namespace Eucolus
{
	class Component
	{
	public:
		Component();
		~Component();

		virtual bool Init();
		virtual void Update();
		virtual void Render();
	};
}
