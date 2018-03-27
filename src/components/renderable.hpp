#pragma once

#include <SFML\Graphics\Texture.hpp>

// todo animated sprite handling
struct Renderable
{
	Renderable(sf::Texture &texture) : texture(&texture) {}

	sf::Texture *texture;
};