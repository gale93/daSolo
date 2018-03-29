#pragma once

namespace GameEvent
{
	struct SpawnSoldier
	{
		SpawnSoldier(const sf::Vector2f & position, bool controlled) : position(position), controlled(controlled) {}
		sf::Vector2f position;
		bool controlled;
	};
};
