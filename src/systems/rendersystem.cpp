#include "engine.hpp"
#include "rendersystem.hpp"

#include <SFML\Graphics\Sprite.hpp>

#include "components\renderable.hpp"
#include "components\body.hpp"

#include "utils.hpp"

RenderSystem::RenderSystem(sf::RenderWindow* window) : window(window)
{

}

void RenderSystem::update(const float alpha)
{
	auto  lerp = [](float t, const b2Vec2& a, const b2Vec2& b) -> b2Vec2 {
		return (1 - t)*a + t * b;
	};

	sf::Sprite sprite;

	registry->view<Renderable, Body>().each([&](auto entity, Renderable &renderable, Body &body)
	{
		auto position = body.body->GetPosition();
		if (position != renderable.current_position)
		{
			renderable.last_position = renderable.current_position;
			renderable.current_position = position;
		}

		position = lerp(alpha, renderable.last_position, renderable.current_position);
		position *= METER_TO_PIXEL;

		sprite.setTexture(*renderable.texture);
		sprite.setOrigin(static_cast<sf::Vector2f>(renderable.texture->getSize()) * 0.5f);
		sprite.setRotation(360 - (body.body->GetAngle() * RADIAN_TO_DEGREES));
		sprite.setPosition(sf::Vector2f(position.x, position.y));
		window->draw(sprite);
	});
}