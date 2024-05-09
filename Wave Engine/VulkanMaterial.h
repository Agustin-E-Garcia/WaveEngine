#pragma once
#include "vulkan/vulkan.h"

class VulkanMaterial
{
public:
	VulkanMaterial(const VkDevice& device, const VkRenderPass& renderPass, const char* vertexShader, const char* fragmentShader, int* id);
	void Cleanup(const VkDevice& device);

	operator VkPipeline() { return _graphicsPipeline; }
	void PushConstants(VkCommandBuffer& commandBuffer, glm::mat4 viewMatrix, glm::mat4 projectionMatrix);

private:
	int _ID;
	const char* _vertex;
	const char* _fragment;
	VkPipelineLayout _pipelineLayout;
	VkPipeline _graphicsPipeline;

	void CreateGraphicsPipeline(const VkDevice& device, const VkRenderPass& renderPass);
};