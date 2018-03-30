#include "engine.hpp"
#include "rendersystem.hpp"

#include <SFML\Graphics\Sprite.hpp>

#include "components\renderable.hpp"
#include "components\body.hpp"

using namespace GameComponent;

RenderSystem::RenderSystem(sf::RenderWindow* window) : window(window)
{

}

void RenderSystem::update(const float alpha)
{
	auto  lerp = [](float t, const sf::Vector2f& a, const sf::Vector2f& b) -> sf::Vector2f {
		return (1 - t)*a + t * b;
	};

	sf::Sprite sprite;

	registry->view<Renderable, Body>().each([&](auto entity, Renderable &renderable, Body &body)
	{
		auto position = body.position;
		if (position != renderable.current_position)
		{
			renderable.last_position = renderable.current_position;
			renderable.current_position = position;
		}

		position = lerp(alpha, renderable.last_position, renderable.current_position);

		sprite.setTexture(*renderable.texture);
		sprite.setOrigin(static_cast<sf::Vector2f>(renderable.texture->getSize()) * 0.5f);
		sprite.setRotation(body.angle);
		sprite.setPosition(sf::Vector2f(position.x, position.y));
		window->draw(sprite);
	});
}