#include "engine.hpp"
#include "gamescene.hpp"

#include "systems\physicssystem.hpp"
#include "systems\rendersystem.hpp"
#include "systems\spawnsystem.hpp"
#include "systems\playercontrolsystem.hpp"

GameScene::GameScene() : Scene("game")
{

}


GameScene::~GameScene()
{
}

void GameScene::init()
{
	em.init(engine);

	auto physicssystem = std::make_unique<PhysicsSystem>();
	auto spawnsystem = std::make_unique<SpawnSystem>(physicssystem->getWorld());

	em.addSystem(std::make_unique<PlayerControlSystem>(&engine->getWindow()));
	em.addSystem(std::move(physicssystem));
	em.addSystem(std::move(spawnsystem));

	em.addRenderSystem(std::make_unique<RenderSystem>(&engine->getWindow()));

	// do spawn our ship
	em.getEventDispatcher()->trigger<SpawnShip>(b2Vec2(5, 5), true);
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
	em.onUpdate(dt);
}

void GameScene::render(const float alpha_lerp)
{
	window->clear();
	em.onRender(alpha_lerp);
	window->display();
}
