#include "engine.hpp"
#include "spawnsystem.hpp"

#include "components\aicontroller.hpp"
#include "components\body.hpp"
#include "components\playercontroller.hpp"
#include "components\renderable.hpp"

SpawnSystem::SpawnSystem()
{
	
}

void SpawnSystem::onInit()
{
	eventDispatcher->connect<SpawnShip>(this);
}

void SpawnSystem::receive(const SpawnShip &event)
{
	auto& textureMng = engine->getTextureManager();
	auto entity = registry->create(
		Body {event.position},
		Renderable{ textureMng.get("code/assets/placeholder.png"), event.position }
	);

	if (event.controlled)
		registry->assign<PlayerController>(entity);
	else
		registry->assign<AIController>(entity);
}
