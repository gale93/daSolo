#include "playercontrolsystem.hpp"

#include "components\playercontroller.hpp"
#include "components\body.hpp"

#include <SFML\Window\Keyboard.hpp>

void PlayerControlSystem::handleKeyStatus()
{
	// todo one day, key code configuration
	ctrls.left	= sf::Keyboard::isKeyPressed(sf::Keyboard::A);
	ctrls.right = sf::Keyboard::isKeyPressed(sf::Keyboard::D);
	ctrls.spin	= sf::Keyboard::isKeyPressed(sf::Keyboard::W);
}

void PlayerControlSystem::update(const float dt)
{
	handleKeyStatus();
	registry->view<PlayerController, Body>().each([&](auto entity, PlayerController &c, Body &bodycomponent) {
	});
}

