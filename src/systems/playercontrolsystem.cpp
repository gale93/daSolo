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

void PlayerControlSystem::handleKeyStatus()
{
	// todo one day, key code configuration
	ctrls.fire = sf::Keyboard::isKeyPressed(sf::Keyboard::Space);
	ctrls.spin = sf::Keyboard::isKeyPressed(sf::Keyboard::W);
}

b2Vec2 PlayerControlSystem::getMousePosition()
{
	auto m = static_cast<sf::Vector2f>(sf::Mouse::getPosition(*window)) * PIXEL_TO_METER;
	return b2Vec2(m.x, m.y);
}

void PlayerControlSystem::update(const float dt)
{
	handleKeyStatus();
	const auto mousePos = getMousePosition();

	registry->view<PlayerController, Body>().each([&](auto entity, PlayerController &c, Body &bodycomponent) {
		auto body = bodycomponent.body;

		// rotate player towards mouse
		auto targetDir = b2Vec2(mousePos.x, mousePos.y) - body->GetPosition();
		body->SetTransform(body->GetPosition(), atan2f(-targetDir.y, targetDir.x));

		if (ctrls.spin)
		{
			auto angle = body->GetAngle();
			auto dir = b2Vec2(cos(angle), sin(angle));
			body->ApplyLinearImpulse(dir, body->GetWorldCenter(), true);
		}
	});
}

