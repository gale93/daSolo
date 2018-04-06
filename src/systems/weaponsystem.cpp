#include "engine.hpp"
#include "weaponsystem.hpp"

#include "components\weapon.hpp"
#include "components\playerstate.hpp"

using namespace GameComponent;

void WeaponSystem::update(const float dt)
{
	registry->view<Weapon, PlayerState>().each([&](auto entity, Weapon &w, PlayerState& ps) {
	});
}

