#pragma once

#include <Box2D\Dynamics\b2Body.h>


struct Body
{
	b2Body* body;

	float32 speed = 15.f;
};