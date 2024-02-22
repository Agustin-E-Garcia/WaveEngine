#pragma once
#define GLFW_INCLUDE_VULKAN
#include<GLFW/glfw3.h>
#include"VulkanDevice.h"

class RenderingManager
{
public:
	RenderingManager(GLFWwindow* window);
	~RenderingManager();
private:
	VkInstance vulkanInstance;
	VkDebugUtilsMessengerEXT debugMessenger;
	VkSurfaceKHR vulkanSurface;
	VulkanDevice vulkanDevice;

	void CreateInstance(GLFWwindow* window);
	
	// Debug functions
	void SetupDebugMessenger();
	bool CheckValidationLayerSupport();
	VkResult CreateDebugUtilsMessengerEXT(VkInstance instance, const VkDebugUtilsMessengerCreateInfoEXT* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDebugUtilsMessengerEXT* pDebugMessenger);
	void DestroyDebugUtilsMessengerEXT(VkInstance instance, VkDebugUtilsMessengerEXT debugMessenger, const VkAllocationCallbacks* pAllocator);
};