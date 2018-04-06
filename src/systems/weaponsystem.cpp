#include "engine.hpp"
#include "weaponsystem.hpp"

#include "components\weapon.hpp"
#include "components\playerstate.hpp"

using namespace GameComponent;

void WeaponSystem::update(const float dt)
{
	auto view = registry->view<Weapon, PlayerState>();

	for (auto entity : view)
	{
		auto &weapon = view.get<Weapon>(entity);
		auto &state = view.get<PlayerState>(entity);

		if (weapon.current_ammo == 0)
		{
			weapon.current_reload_time += dt;
			if (weapon.current_reload_time >= weapon.reload_time)
			{
				weapon.current_ammo = weapon.ammo;
				weapon.current_reload_time = 0.f;
			}
		}
		else if (weapon.current_fire_rate < weapon.fire_rate)
		{
			weapon.current_fire_rate += dt;;
		}
		else if (state.shooting)
		{
			weapon.current_fire_rate = 0.f;
			weapon.current_ammo--;
			// do shoot
		}
	}
}

