#pragma once

#include <entt\entity\registry.hpp>
#include <entt\signal\dispatcher.hpp>

class BaseSystem
{
protected:
	class Engine* engine;
	entt::DefaultRegistry* registry;
	entt::UnmanagedDispatcher* eventDispatcher;
public:
	BaseSystem();
	~BaseSystem();

	void init(Engine *e, entt::DefaultRegistry& r, entt::UnmanagedDispatcher& d);

	virtual void update(const float dt);
};

