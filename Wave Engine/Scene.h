#pragma once
#include "enTT/entt.hpp"

class Scene
{
private:
	entt::registry _registry;
	entt::entity _cameraEntity;

public:
	Scene();
	~Scene();

	entt::entity AddEntity();

	template<typename T>
	T AddComponent(const entt::entity entity);

	void QueryEntities();
};