#pragma once

#include <SFML\Graphics\Texture.hpp>
#include <Box2D\Common\b2Math.h>

// todo animated sprite handling
struct Renderable
{
	Renderable(sf::Texture &texture, const b2Vec2& pos) : texture(&texture), last_position(pos), current_position(pos) {}

	sf::Texture *texture;
	b2Vec2 last_position, current_position;
};