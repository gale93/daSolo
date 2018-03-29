#include "engine.hpp"
#include "scene.hpp"


Scene::Scene(const std::string& name) : name(name)
{
}

Scene::~Scene()
{
}

void Scene::setEngine(Engine *engine)
{
	this->engine = engine;

	window = &engine->getWindow();
	sceneMng = &engine->getSceneManager();
	textureMng = &engine->getTextureManager();
}

void Scene::handleDefaultEvents(sf::Event *event)
{
	if (event->type == sf::Event::Closed ||
		event->type == sf::Event::KeyPressed && event->key.code == sf::Keyboard::Escape)
		engine->stop();

	// todo handle here resizing window and black border bars for resolution
}