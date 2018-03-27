#include "../engine.hpp"
#include "basesystem.hpp"


BaseSystem::BaseSystem()
{
}


BaseSystem::~BaseSystem()
{
}

void BaseSystem::init(Engine * e, entt::DefaultRegistry& r, entt::UnmanagedDispatcher& d)
{
	 registry = &r;
	 eventDispatcher = &d;
	 engine = e;

	 onInit();
}


void BaseSystem::update(const float dt)
{
}
