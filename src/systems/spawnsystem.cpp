#include "engine.hpp"
#include "spawnsystem.hpp"

#include "components\aicontroller.hpp"
#include "components\body.hpp"
#include "components\playercontroller.hpp"
#include "components\renderable.hpp"

using namespace GameComponent;

SpawnSystem::SpawnSystem()
{
	
}

void SpawnSystem::onInit()
{
	eventDispatcher->connect<GameEvent::SpawnSoldier>(this);
}

void SpawnSystem::receive(const GameEvent::SpawnSoldier &event)
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
