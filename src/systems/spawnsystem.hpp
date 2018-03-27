#pragma once

#include "physicssystem.hpp"

#include "events\spawnship.hpp"

class SpawnSystem : public BaseSystem
{
	PhysicsSystem *physicsSys;

	void onInit() override;
public:
	SpawnSystem(PhysicsSystem *);

	void receive(const SpawnShip &);
};