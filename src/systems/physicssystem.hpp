#pragma once

#include "basesystem.hpp"

class PhysicsSystem :  public BaseSystem
{
public:
	PhysicsSystem();

	void update(const float dt) override;
};