#pragma once

#include "basesystem.hpp"
#include <Box2D\Common\b2Math.h>


class PlayerControlSystem : public BaseSystem
{
	class sf::RenderWindow* window;

	bool isSpinning();

	b2Vec2 getMousePosition();
public:
	PlayerControlSystem(sf::RenderWindow* window);

	void update(const float dt) override;
};