#pragma once

#include <Box2D\Common\b2Math.h>

struct SpawnShip
{
	SpawnShip(const b2Vec2& position, bool controlled) : position(position), controlled(controlled) {}
	b2Vec2 position;
	bool controlled;
};