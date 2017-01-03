#include "World.h"
#include "Entity.h"

namespace Eucolus
{
	World::World()
	{
	}

	World::~World()
	{
	}

	bool World::Init()
	{
		auto entity = std::make_shared<Entity>();

		auto renderComponent = std::make_shared<RenderComponent>();

		entity->AddComponent(renderComponent);

		return false;
	}

	void World::Update()
	{
	}

	void World::Render()
	{
	}
}
