#pragma once
#include "enTT/entt.hpp"
#include "Components.h"

class Scene
{
private:
	entt::registry _registry;
	entt::entity _cameraEntity;

public:
	Scene();
	~Scene();

	entt::entity AddEntity();

	entt::registry& Registry() { return _registry; }
};