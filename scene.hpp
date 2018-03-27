#pragma once

#include <string>

class Scene
{
	std::string name;
protected:
	class Engine *engine;

	class SceneManager *sceneMng;
	class EntityManager *entityMng;
	class Window *window;
	class NetManager *netMng;
public:
	Scene(const std::string& name);
	~Scene();

	void setEngine(Engine *engine);
	inline const std::string& getName() { return name; }

	inline virtual void init() {}
	inline virtual void onUpdate() {}
	inline virtual void onFixedUpdate(const float dt) {}
	inline virtual void onRender(const float alpha_lerp) {}
};

