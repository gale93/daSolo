#pragma once

#include "basesystem.hpp"
#include <Box2D\Dynamics\b2World.h>

class PhysicsSystem :  public BaseSystem
{
	std::unique_ptr<b2World> world;
public:
	PhysicsSystem();

	void update(const float dt) override;

	b2World *getWorld() { return world.get(); }
};