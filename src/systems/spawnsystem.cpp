#include "engine.hpp"
#include "spawnsystem.hpp"

#include <Box2D\Box2D.h>

#include "components\aicontroller.hpp"
#include "components\body.hpp"
#include "components\playercontroller.hpp"
#include "components\renderable.hpp"

SpawnSystem::SpawnSystem(b2World *phyWorld) : phyWorld(phyWorld)
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
		Renderable{ textureMng.get("assets/placeholder.png"), event.position }
	);

	b2BodyDef myBodyDef;
	myBodyDef.type = b2_dynamicBody;
	myBodyDef.position = event.position;

	Body body;
	body.body = phyWorld->CreateBody(&myBodyDef);

	b2PolygonShape boxShape;
	boxShape.SetAsBox(2, 1);

	b2FixtureDef boxFixtureDef;
	boxFixtureDef.shape = &boxShape;
	boxFixtureDef.density = 1;
	body.body->CreateFixture(&boxFixtureDef);

	body.body->SetUserData((void *)entity);
	registry->assign<Body>(entity, body);

	if (event.controlled)
		registry->assign<PlayerController>(entity);
	else
		registry->assign<AIController>(entity);
}
