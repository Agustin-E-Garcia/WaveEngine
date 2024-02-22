#pragma once
#include "Config.h"
#include "Utils.h"

using QueueFamilyIndices = VkDataStructure::QueueFamilyIndices;
using SwapChainSupportDetails = VkDataStructure::SwapChainSupportDetails;

class VulkanDevice
{
public:
	void InitDevice(const VkInstance& instance, const VkSurfaceKHR& surface);
	void CleanupDevice();
private:
	VkPhysicalDevice physicalDevice;
	QueueFamilyIndices familyIndices;
	SwapChainSupportDetails swapChainSupportDetails;
	
	VkDevice logicalDevice;
	VkQueue graphicsQueue;
	VkQueue presentQueue;
	
	VkSwapchainKHR swapChain;
	VkFormat swapChainImageFormat;
	VkExtent2D swapChainExtent;
	std::vector<VkImageView> swapChainImageViews;

	// Physical Device
	void PickPhysicalDevice(const VkInstance& instance, const VkSurfaceKHR& surface);
	bool IsDeviceSuitable(VkPhysicalDevice device, const VkSurfaceKHR& surface);
	QueueFamilyIndices FindQueueFamilies(VkPhysicalDevice device, const VkSurfaceKHR& surface);
	bool CheckDeviceExtensionSupport(VkPhysicalDevice device);
	SwapChainSupportDetails QuerySwapChainSupport(VkPhysicalDevice device, const VkSurfaceKHR& surface);

	void CreateLogicalDevice();

	void CreateSwapChain(const VkSurfaceKHR& surface);
	VkSurfaceFormatKHR ChooseSwapSurfaceFormat(const std::vector<VkSurfaceFormatKHR>& availableFormats);
	VkPresentModeKHR ChooseSwapPresentMode(const std::vector<VkPresentModeKHR>& availablePresentModes);
	VkExtent2D ChooseSwapExtent(const VkSurfaceCapabilitiesKHR& capabilities);
	
	void CreateImageViews();
};