#include "Scene.h"
#include "Components.h"

Scene::Scene()
{
	_cameraEntity = AddEntity();
	_registry.emplace<Components::Camera>(_cameraEntity);

	auto entity1 = AddEntity();
	_registry.emplace<Components::Mesh>(entity1);

	auto entity2 = AddEntity();
	_registry.emplace<Components::Mesh>(entity2);
	auto& comp = _registry.get<Components::Transform>(entity2);
	comp.position = glm::vec3(2.0f, 0.0f, 0.0f);
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