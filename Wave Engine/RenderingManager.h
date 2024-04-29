#pragma once
#include "GLFW/glfw3.h"
#include "VulkanRenderer.h"

class RenderingManager
{
public:
	RenderingManager();
	~RenderingManager();

	void Run();
	static void ResizeCallback(GLFWwindow* window, int width, int height);

	GLFWwindow* window = nullptr;
	void(*resizeFunction)(int width, int height);
};