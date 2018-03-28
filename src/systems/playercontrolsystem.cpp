#include "playercontrolsystem.hpp"

#include "components\playercontroller.hpp"
#include "components\body.hpp"

void PlayerControlSystem::update(const float dt)
{
	registry->view<PlayerController, Body>().each([](auto entity, PlayerController &c, Body &body) {
	});
}

