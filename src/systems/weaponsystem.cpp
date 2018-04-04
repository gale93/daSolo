#include "engine.hpp"
#include "weaponsystem.hpp"

#include "components\weapon.hpp"

void WeaponSystem::update(const float dt)
{
	registry->view<GameComponent::Weapon>().each([&](auto entity, GameComponent::Weapon &w) {

	});
}

