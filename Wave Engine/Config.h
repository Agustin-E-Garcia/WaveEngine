#pragma once
#include <vector>
#include <vulkan/vulkan.h>

namespace VkConfig 
{
	static const int MAX_FRAMES_IN_FLIGHT = 2;

	static const std::vector<const char*> ValidationLayers = { "VK_LAYER_KHRONOS_validation" };
	static const std::vector<const char*> DeviceExtensions = { VK_KHR_SWAPCHAIN_EXTENSION_NAME };

#ifdef NDEBUG
	static const bool enableValidationLayers = false;
#else
	static const bool enableValidationLayers = true;
#endif
}