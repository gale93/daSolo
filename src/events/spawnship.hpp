#pragma once

struct SpawnShip
{
	SpawnShip(const sf::Vector2f & position, bool controlled) : position(position), controlled(controlled) {}
	sf::Vector2f position;
	bool controlled;
};