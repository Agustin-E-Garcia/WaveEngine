#include "Scene.h"
#include "Components.h"

Scene::Scene()
{
	_cameraEntity = AddEntity();
	_registry.emplace<Components::Camera>(_cameraEntity);

	auto entity1 = AddEntity();
	_registry.emplace<Components::Mesh>(entity1, "Plane");

	auto entity2 = AddEntity(glm::vec3(2.0f, 0.0f, 0.0f));
	_registry.emplace<Components::Mesh>(entity2, "Plane");

	auto entity3 = AddEntity(glm::vec3(-2.0f, 0.0f, 0.0f));
	_registry.emplace<Components::Mesh>(entity3, "Plane");

	auto entity4 = AddEntity(glm::vec3(0.0f, 2.0f, 0.0f));
	_registry.emplace<Components::Mesh>(entity4, "Plane");
}

Scene::~Scene()
{
}

entt::entity Scene::AddEntity()
{
	return AddEntity(glm::vec3(0.0f));
}

entt::entity Scene::AddEntity(glm::vec3 position)
{
	entt::entity newEntity = _registry.create();
	_registry.emplace<Components::Transform>(newEntity).position = position;

	return newEntity;
}