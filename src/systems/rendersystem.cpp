#include "engine.hpp"
#include "rendersystem.hpp"

#include <SFML\Graphics\Sprite.hpp>

#include "components\renderable.hpp"
#include "components\body.hpp"

#define METER_TO_PIXEL 16

RenderSystem::RenderSystem(sf::RenderWindow* window) : window(window)
{

}

void RenderSystem::update(const float alpha)
{
	auto  lerp = [](float t, const b2Vec2& a, const b2Vec2& b) -> b2Vec2 {
		return (1 - t)*a + t * b;
	};

	sf::Sprite sprite;

	auto view = registry->view<Body, Renderable>();
	for (auto entity : view)
	{
		auto& renderable = view.get<Renderable>(entity);
		auto position = view.get<Body>(entity).body->GetPosition();

		sprite.setTexture(*renderable.texture);

		position = lerp(alpha, renderable.last_position, position);
		position *= METER_TO_PIXEL;
		sprite.setPosition(sf::Vector2f(position.x, position.y));
	}
}