#pragma once
#include <vulkan/vulkan.h>
#include <vector>
#include <optional>
#include <fstream>

namespace Utils
{
	static std::vector<char> ReadFile(const std::string& filename)
	{
		std::vector<char> buffer;
		std::ifstream file(filename, std::ios::ate | std::ios::binary);

		if (!file.is_open()) return buffer;

		size_t fileSize = (size_t)file.tellg();
		buffer.reserve(fileSize);

		file.seekg(0);
		file.read(buffer.data(), fileSize);

		file.close();

		return buffer;
	}
};

namespace VkDataStructure
{
	struct QueueFamilyIndices
	{
		std::optional<uint32_t> graphicsFamily;
		std::optional<uint32_t> presentFamily;

		bool isComplete() { return graphicsFamily.has_value() && presentFamily.has_value(); }
	};

	struct SwapChainSupportDetails
	{
		VkSurfaceCapabilitiesKHR capabilities;
		std::vector<VkSurfaceFormatKHR> formats;
		std::vector<VkPresentModeKHR> presentModes;
	};

	struct SwapChainCreateInfo 
	{
		VkSurfaceKHR& surface;
		VkPhysicalDevice physicalDevice;
		VkDevice logicalDevice;
		QueueFamilyIndices familyIndices;
		SwapChainSupportDetails swapChainSupport;
	};
}