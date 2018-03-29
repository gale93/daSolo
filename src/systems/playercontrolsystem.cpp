#include "engine.hpp"
#include "playercontrolsystem.hpp"

#include "components\playercontroller.hpp"
#include "components\body.hpp"

#include <SFML\Window\Keyboard.hpp>
#include <SFML\Window\Mouse.hpp>

#include "utils.hpp"

PlayerControlSystem::PlayerControlSystem(sf::RenderWindow* window) : window(window)
{
}

bool PlayerControlSystem::isSpinning()
{
	return sf::Keyboard::isKeyPressed(sf::Keyboard::W);
}

b2Vec2 PlayerControlSystem::getMousePosition()
{
	auto m = static_cast<sf::Vector2f>(sf::Mouse::getPosition(*window)) * PIXEL_TO_METER;
	return b2Vec2(m.x, m.y);
}


void PlayerControlSystem::update(const float dt)
{
	const auto mousePos = getMousePosition();

	registry->view<PlayerController, Body>().each([&](auto entity, PlayerController &c, Body &bodycomponent) {
		auto body = bodycomponent.body;

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
			body->SetTransform(body->GetWorldCenter(), body->GetAngle() + 1.f);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
			body->ApplyAngularImpulse(-0.1f, true);

		if (isSpinning())
		{
			auto angle = body->GetAngle();
			auto dir = b2Vec2(cos(angle), -sin(angle));
			dir *= bodycomponent.speed;

			body->ApplyLinearImpulseToCenter(dir, true);

			if (body->GetLinearVelocity().Length() > bodycomponent.speed)
			{
				dir = body->GetLinearVelocity();
				dir.Normalize();
				dir *= bodycomponent.speed;

				body->SetLinearVelocity(dir);
			}
				
		}

	});
}

