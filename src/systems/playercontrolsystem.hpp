#pragma once

#include "basesystem.hpp"


class PlayerControlSystem : public BaseSystem
{
	class sf::RenderWindow* window;

	sf::Vector2f getMousePosition();
public:
	PlayerControlSystem(sf::RenderWindow* window);

	void update(const float dt) override;
};