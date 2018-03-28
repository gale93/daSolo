#include "engine.hpp"
#include "rendersystem.hpp"

#include <SFML\Graphics\Sprite.hpp>

#include "components\renderable.hpp"
#include "components\body.hpp"

#define METER_TO_PIXEL 16
#define RADIAN_TO_DEGREES 180.f/3.1415

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
		sprite.setPosition(sf::Vector2f(position.x, position.y));
		sprite.setRotation(360 - (body.body->GetAngle() * RADIAN_TO_DEGREES));
		window->draw(sprite);
	});
}