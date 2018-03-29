#pragma once

#include <SFML\Graphics\Texture.hpp>

// todo animated sprite handling
struct Renderable
{
	Renderable(sf::Texture &texture, const sf::Vector2f& pos) : texture(&texture), last_position(pos), current_position(pos) {}

	sf::Texture *texture;
	sf::Vector2f last_position, current_position;
};