#include "engine.hpp"
#include "playercontrolsystem.hpp"

#include "components\playercontroller.hpp"
#include "components\body.hpp"

#include <SFML\Window\Keyboard.hpp>
#include <SFML\Window\Mouse.hpp>

PlayerControlSystem::PlayerControlSystem(sf::RenderWindow* window) : window(window)
{
}

sf::Vector2f PlayerControlSystem::getMousePosition()
{
	return static_cast<sf::Vector2f>(sf::Mouse::getPosition(*window));
}


void PlayerControlSystem::update(const float dt)
{
	const auto mousePos = getMousePosition();

	registry->view<PlayerController, Body>().each([&](auto entity, PlayerController &c, Body &bodycomponent) {
	});
}

