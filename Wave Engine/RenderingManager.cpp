#include "RenderingManager.h"

RenderingManager::RenderingManager() 
{
	glfwInit();
	glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
	window = glfwCreateWindow(WIDTH, HEIGHT, "Vulkan", nullptr, nullptr);
}

RenderingManager::~RenderingManager() 
{
	glfwDestroyWindow(window);
	glfwTerminate();
}

void RenderingManager::Run()
{
	VulkanRenderer vulkan(window, resizeFunction);
	
	//glfwSetWindowUserPointer(window, this);
	//glfwSetFramebufferSizeCallback(window, ResizeCallback);

	while (!glfwWindowShouldClose(window))
	{
		glfwPollEvents();
		vulkan.Draw();
	}
	vulkan.Cleanup();
}

void RenderingManager::ResizeCallback(GLFWwindow* window, int width, int height)
{
	//auto app = reinterpret_cast<RenderingManager*>(glfwGetWindowUserPointer(window));
	//app->resizeFunction(width, height);
}