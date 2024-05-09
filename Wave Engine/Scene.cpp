#include "Scene.h"
#include "Components.h"

Scene::Scene()
{
	_cameraEntity = AddEntity();
	_registry.emplace<Components::Camera>(_cameraEntity);

	auto entity = AddEntity();
	_registry.emplace<Components::Mesh>(entity);
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