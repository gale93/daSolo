#include "engine.hpp"
#include "gamescene.hpp"

GameScene::GameScene() : Scene("game")
{

}


GameScene::~GameScene()
{
}

void GameScene::init()
{
}

void GameScene::update()
{
	sf::Event event;
	while (window->pollEvent(event))
	{
		handleDefaultEvents(&event);

	}
}

void GameScene::fixedupdate(const float dt)
{
}

void GameScene::render(const float alpha_lerp)
{
	window->clear();
	window->display();
}
