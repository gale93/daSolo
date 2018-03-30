#include "engine.hpp"
#include "game.hpp"

#include "systems\physicssystem.hpp"
#include "systems\rendersystem.hpp"
#include "systems\spawnsystem.hpp"
#include "systems\playercontrolsystem.hpp"

using namespace GameScene;

Game::Game() : Scene("game")
{

}


Game::~Game()
{
}

void Game::init()
{
	em.init(engine);

	auto physicssystem = std::make_unique<PhysicsSystem>();
	auto spawnsystem = std::make_unique<SpawnSystem>();

	em.addSystem(std::make_unique<PlayerControlSystem>(&engine->getWindow()));
	em.addSystem(std::move(physicssystem));
	em.addSystem(std::move(spawnsystem));

	em.addRenderSystem(std::make_unique<RenderSystem>(&engine->getWindow()));

	loadLevel();
}

void Game::loadLevel()
{
	/* todo from file */

	// do spawn our soldier
	em.getEventDispatcher()->trigger<GameEvent::SpawnSoldier>(sf::Vector2f(5, 5), true);

	// spawn some other soldiers
	for (unsigned short i = 0; i < 10; i++)
		em.getEventDispatcher()->trigger<GameEvent::SpawnSoldier>(sf::Vector2f(std::rand() % 800, std::rand() % 600), false);
}

void Game::update()
{
	sf::Event event;
	while (window->pollEvent(event))
	{
		handleDefaultEvents(&event);
	}
}

void Game::fixedupdate(const float dt)
{
	em.onUpdate(dt);
}

void Game::render(const float alpha_lerp)
{
	window->clear(sf::Color(83, 83, 83));
	em.onRender(alpha_lerp);
	window->display();
}
