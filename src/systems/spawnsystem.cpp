#include "engine.hpp"
#include "spawnsystem.hpp"

#include <Box2D\Box2D.h>

#include "components\renderable.hpp"
#include "components\body.hpp"

SpawnSystem::SpawnSystem(PhysicsSystem *ps) : physicsSys(ps)
{
	
}

void SpawnSystem::onInit()
{
	eventDispatcher->connect<SpawnShip>(this);
}

void SpawnSystem::receive(const SpawnShip &event)
{
	b2BodyDef myBodyDef;
	myBodyDef.type = b2_dynamicBody;
	myBodyDef.position = event.position;

	Body body;
	body.body = physicsSys->getWorld()->CreateBody(&myBodyDef);

	b2PolygonShape boxShape;
	boxShape.SetAsBox(1, 0.5);

	b2FixtureDef boxFixtureDef;
	boxFixtureDef.shape = &boxShape;
	boxFixtureDef.density = 1;
	body.body->CreateFixture(&boxFixtureDef);

	auto& textureMng = engine->getTextureManager();
	auto entity = registry->create(
		Renderable{ textureMng.get("assets/placeholder.png") }
	);

	body.body->SetUserData((void *)entity);
	registry->assign<Body>(entity, body);

	if (event.controlled); // todo add AI or PlayerController components
}
