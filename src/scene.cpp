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
}