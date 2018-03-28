#pragma once

#include "basesystem.hpp"

#include "events\spawnship.hpp"

class SpawnSystem : public BaseSystem
{
	class b2World *phyWorld;

	void onInit() override;
public:
	SpawnSystem(b2World *phyWorld);

	void receive(const SpawnShip &);
};