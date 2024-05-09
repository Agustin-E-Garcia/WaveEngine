#pragma once
#include "VulkanRenderer.h"

class Window;
class Scene;

class RenderingManager
{
private:
	VulkanRenderer _vulkanRenderer;
public:
	RenderingManager();
	~RenderingManager();

	bool Initialize(Window& window);
	void Draw(Scene& scene);
	int CreateMaterial(const char* vertexShader, const char* fragmentShader);
};