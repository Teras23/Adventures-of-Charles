#include "Entity.h"

namespace Eucolus
{
	GameObject::GameObject()
	{
	}

	GameObject::~GameObject()
	{
	}

	bool GameObject::Init()
	{
		return false;
	}

	void GameObject::Update()
	{
		for (std::shared_ptr<Component> component : m_components)
		{
			component->Update();
		}
	}

	void GameObject::AddComponent(std::shared_ptr<Component> c)
	{
		m_components.push_back(c);
	}

	template <class T>
	std::shared_ptr<Component> GameObject::GetComponent()
	{
		for(std::shared_ptr<Component> component : m_components)
		{
			if(typeid(component).name() == typeid(T).name())
			{
				return component;
			}
		}
	}
}
