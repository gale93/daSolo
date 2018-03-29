#include "physicssystem.hpp"

#include "engine.hpp"
#include "components\body.hpp"

PhysicsSystem::PhysicsSystem()
{
}

void PhysicsSystem::update(const float dt)
{
	registry->view<Body>().each([dt](auto entity, Body &body) {
		body.position += body.direction * dt;
	});
}