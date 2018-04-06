#pragma once

namespace GameComponent
{
	enum WEAPON_NAME
	{
		HANDGUN = 0,
		RIFLE0
	};
	
	struct Weapon
	{
		Weapon(WEAPON_NAME name) : name(name)
		{
			_loadWeapon();
		}

		unsigned __int8 name;

		unsigned short ammo;
		unsigned short current_ammo = 0;

		float reload_time;
		float current_reload_time = 0.f;

		float fire_rate;
		float current_fire_rate = 0.f;

		unsigned short damage;

		// todo nice loader from file outside this class
		inline void _loadWeapon()
		{
			switch (name)
			{
			default:
			case HANDGUN:
				damage = 6;
				ammo = 8;
				reload_time = 3;
				fire_rate = 0.8f;
				break;
			}
		}
	};
};