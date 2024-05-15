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

	DrawData drawData{};
	drawData.instanceCount = 0;

	std::set<const char*> meshesAdded;

	for (auto &&[entity, transform, mesh] : view.each())
	{
		if(meshesAdded.count(mesh.modelName) == 0)
		{
			meshesAdded.insert(mesh.modelName);

			drawData.vertices.insert(drawData.vertices.end(), mesh._vertices.begin(), mesh._vertices.end());
			drawData.indices.insert(drawData.indices.end(), mesh._indices.begin(), mesh._indices.end());
		}

		drawData.instanceCount += 1;
		drawData.modelMatrices.push_back(transform.GetModelMatrix());
	}

	_vulkanRenderer.Draw(drawData);
}

int RenderingManager::CreateMaterial(const char* vertexShader, const char* fragmentShader)
{
	return _vulkanRenderer.CreateMaterial(vertexShader, fragmentShader);
}