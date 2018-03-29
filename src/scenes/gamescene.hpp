#pragma once

#include "scene.hpp"
#include "entitymanager.hpp"

class GameScene : public Scene
{
	EntityManager em;

	void loadLevel();
public:
	GameScene();
	~GameScene();

	void init() override;
	void update() override;
	void fixedupdate(const float dt) override;
	void render(const float alpha_lerp) override;
};
