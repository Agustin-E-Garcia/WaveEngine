#include "RenderingManager.h"
#include "Scene.h"

RenderingManager::RenderingManager() {}

RenderingManager::~RenderingManager() {}

bool RenderingManager::Initialize(Window& window)
{
	_vulkanRenderer.Initialize(window);
	return true;
}

void RenderingManager::Draw(Scene& scene)
{
	auto view = scene.Registry().view<Components::Transform, Components::Mesh>();

	std::vector<float> vertices;
	std::vector<uint16_t> indices;
	for (auto &&[entity, transform, mesh] : view.each())
	{
		vertices.insert(vertices.end(), mesh._vertices.begin(), mesh._vertices.end());
		indices.insert(indices.end(), mesh._indices.begin(), mesh._indices.end());
	}

	_vulkanRenderer.Draw(vertices, indices);
}

int RenderingManager::CreateMaterial(const char* vertexShader, const char* fragmentShader)
{
	return _vulkanRenderer.CreateMaterial(vertexShader, fragmentShader);
}