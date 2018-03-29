#pragma once

#include <SFML\System\Vector2.hpp>


struct Body
{
	Body(const sf::Vector2f& position) : position(position) {}

	sf::Vector2f position, direction;
	float angle = 0.f;
	float speed = 100.f;
};