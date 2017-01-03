#pragma once
#include "Component.h"
#include "Utility/Utility.h"
#include <vector>
#include <memory>
#include "Components/RenderComponent.h"

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
