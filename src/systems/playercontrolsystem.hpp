#pragma once

#include "basesystem.hpp"
#include <Box2D\Common\b2Math.h>

// this struct has to be moved to the relative controllers' components
struct controls {
	bool spin, fire;
};

class PlayerControlSystem : public BaseSystem
{
	class sf::RenderWindow* window;

	controls ctrls;
	void handleKeyStatus();

	b2Vec2 getMousePosition();
public:
	PlayerControlSystem(sf::RenderWindow* window);

	void update(const float dt) override;
};