#pragma once

#include "basesystem.hpp"


class PlayerControlSystem : public BaseSystem
{
	class sf::RenderWindow* window;

	sf::Vector2f getMousePosition() const;
	float getAngleToMouse(const sf::Vector2f& position) const;

	sf::Vector2f getPlayerDirection() const;
	bool getPlayerAction() const;
public:
	PlayerControlSystem(sf::RenderWindow* window);

	void update(const float dt) override;
};