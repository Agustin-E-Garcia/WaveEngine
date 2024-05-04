#include "Scene.h"
#include "Components.h"

Scene::Scene()
{
	_cameraEntity = AddEntity();
	AddComponent<Components::Camera>(_cameraEntity);
}

Scene::~Scene()
{
}

entt::entity Scene::AddEntity()
{
	entt::entity newEntity = _registry.create();
	_registry.emplace<Components::Transform>(newEntity);

	return newEntity;
}

template<typename T>
T Scene::AddComponent(const entt::entity entity)
{
	return _registry.emplace<T>(entity);
}