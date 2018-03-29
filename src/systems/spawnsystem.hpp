#pragma once

#include "basesystem.hpp"

#include "events\spawnship.hpp"

class SpawnSystem : public BaseSystem
{
	void onInit() override;
public:
	SpawnSystem();

	void receive(const SpawnShip &);
};