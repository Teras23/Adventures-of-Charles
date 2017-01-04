#pragma once

#include "Utility/Utility.h"
#include "World/Component.h"
#include "World/Components/RenderComponent.h"

namespace Eucolus
{
	class GameObject
	{
	public:
		GameObject();
		~GameObject();

		virtual bool Init();
		virtual void Update();
		void AddComponent(std::shared_ptr<Component>);
		template<class T>
		std::shared_ptr<Component> GetComponent();

		std::shared_ptr<RenderComponent> m_renderComponent;

	private:
		std::vector<std::shared_ptr<Component>> m_components;
	};
}
