#pragma once

#include "scene.hpp"

class GameScene : public Scene
{
public:
	GameScene();
	~GameScene();

	void init() override;
	void update() override;
	void fixedupdate(const float dt) override;
	void render(const float alpha_lerp) override;
};
