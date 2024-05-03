#include "RenderingManager.h"

RenderingManager::RenderingManager() : _vulkanRenderer(nullptr) {}

RenderingManager::~RenderingManager() {}

bool RenderingManager::Initialize(Window& window)
{
	_vulkanRenderer = new VulkanRenderer(window);
	return true;
}

void RenderingManager::Loop()
{
	_vulkanRenderer->Draw();
}