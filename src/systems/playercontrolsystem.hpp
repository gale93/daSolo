#pragma once
#include "basesystem.hpp"

// this struct has to be moved to the relative controllers' components
struct controls {
	bool left, right, spin;
};

class PlayerControlSystem : public BaseSystem
{
	controls ctrls;
	void handleKeyStatus();
public:

	void update(const float dt) override;
};