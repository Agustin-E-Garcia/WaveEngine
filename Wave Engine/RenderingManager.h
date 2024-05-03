#pragma once
#include "VulkanRenderer.h"

class Window;

class RenderingManager
{
private:
	VulkanRenderer* _vulkanRenderer;
public:
	RenderingManager();
	~RenderingManager();

	bool Initialize(Window& window);
	void Loop();
};