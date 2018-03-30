#pragma once

#include "scene.hpp"
#include "entitymanager.hpp"

namespace GameScene
{
	class Game : public Scene
	{
		EntityManager em;

		void loadLevel();
	public:
		Game();
		~Game();

		void init() override;
		void update() override;
		void fixedupdate(const float dt) override;
		void render(const float alpha_lerp) override;
	};
};