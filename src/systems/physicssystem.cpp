#include "physicssystem.hpp"

#include "engine.hpp"
#include "components\body.hpp"

PhysicsSystem::PhysicsSystem()
{
	world = std::make_unique<b2World>(b2Vec2(0,0));
}

void PhysicsSystem::update(const float dt)
{
	world->Step(TIMESTEP_S, 8, 3);
}