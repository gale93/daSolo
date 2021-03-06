#include "engine.hpp"
#include "playercontrolsystem.hpp"

#include "components\playercontroller.hpp"
#include "components\body.hpp"
#include "components\playerstate.hpp"

#include <SFML\Window\Keyboard.hpp>
#include <SFML\Window\Mouse.hpp>


#define RAD_TO_DEG 180.f / 3.1415f

using namespace GameComponent;

PlayerControlSystem::PlayerControlSystem(sf::RenderWindow* window) : window(window)
{
}

sf::Vector2f PlayerControlSystem::getMousePosition() const
{
	return static_cast<sf::Vector2f>(sf::Mouse::getPosition(*window));
}

float PlayerControlSystem::getAngleToMouse(const sf::Vector2f & position) const
{
	auto targetDir = getMousePosition() - position;

	return atan2f(targetDir.y, targetDir.x) * RAD_TO_DEG;
}

sf::Vector2f PlayerControlSystem::getPlayerDirection() const
{
	sf::Vector2f dir;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))		dir.y = -1.f;
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))	dir.y = 1.f;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))		dir.x = -1.f;
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))	dir.x = 1.f;


	if (dir != sf::Vector2f())
	{
		float len = sqrt((dir.x * dir.x) + (dir.y * dir.y));
		dir /= len;
	}

	return dir;
}

bool PlayerControlSystem::getPlayerAction() const
{
	return sf::Mouse::isButtonPressed(sf::Mouse::Left);
}


void PlayerControlSystem::update(const float dt)
{
	auto dir = getPlayerDirection();

	registry->view<PlayerController, Body, PlayerState>().each([&](auto entity, PlayerController &c, Body &body, PlayerState& state)
	{
		body.direction = dir * body.speed;
		body.angle = getAngleToMouse(body.position);

		state.moving = dir != sf::Vector2f();
		state.shooting = getPlayerAction();
	});
}

