#pragma once

#include "basesystem.hpp"

#include "events\spawnsoldier.hpp"

class SpawnSystem : public BaseSystem
{
	void onInit() override;
public:
	SpawnSystem();

	void receive(const GameEvent::SpawnSoldier &);
};