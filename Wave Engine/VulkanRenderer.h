#include "VulkanMaterial.h"
#include <vector>

class Window;

struct DrawData 
{
	std::vector<float> vertices;
	std::vector<uint16_t> indices;

	int instanceCount;
	std::vector<glm::mat4> modelMatrices;
};

class VulkanRenderer
{
public:
	void Initialize(Window& window);
	void Draw(DrawData drawData) { DrawFrame(drawData); }
	void Cleanup();

	int CreateMaterial(const char* vertexShader, const char* fragmentShader);

private:
	VkInstance _instance;
	VkDebugUtilsMessengerEXT _debugMessenger;
	VkSurfaceKHR _surface;
	
	VkPhysicalDevice _physicalDevice = VK_NULL_HANDLE;
	VkDevice _device;

	VkQueue _graphicsQueue;
	VkQueue _presentQueue;

	VkSwapchainKHR _swapChain;
	std::vector<VkImage> _swapChainImages;
	VkFormat _swapChainImageFormat;
	VkExtent2D _swapChainExtent;
	std::vector<VkImageView> _swapChainImageViews;
	std::vector<VkFramebuffer> _swapChainFrameBuffers;

	VkRenderPass _renderPass;
	std::vector<VulkanMaterial> _materialList;

	VkCommandPool _commandPool;
	std::vector<VkCommandBuffer> _commandBuffers;

	std::vector <VkSemaphore> _imageAvailableSemaphores;
	std::vector <VkSemaphore> _renderFinishedSemaphores;
	std::vector <VkFence> _inFlightFences;

	uint32_t _currentFrame = 0;

	std::vector<VkBuffer> _vertexBuffers;
	std::vector<VkDeviceMemory> _vertexBufferMemories;

	std::vector<VkBuffer> _indexBuffers;
	std::vector<VkDeviceMemory> _indexBufferMemories;

	std::vector<VkBuffer> _modelMatrixBuffer;
	std::vector<VkDeviceMemory> _modelMatrixBufferMemories;

	VkBuffer _stagingBuffer;
	VkDeviceMemory _stagingBufferMemory;

	void CreateInstance(const char* title);
	void SetupDebugMessenger();
	void PickPhysicalDevice();
	void CreateLogicalDevice();
	void CreateSurface(Window& window);
	void CreateSwapChain(int width, int height);
	void CreateImageViews();
	void CreateRenderPass();
	void CreateFrameBuffers();
	void CreateCommandPool();
	void CreateCommandBuffers();
	void RecordCommandBuffer(VkCommandBuffer& commandBuffer, VkBuffer& vertexBuffer, VkBuffer& indexBuffer, VkBuffer& modelMatrixBuffer, uint32_t imageIndex, uint32_t indexCount);
	void DrawFrame(DrawData& drawData);
	void CreateSyncObjects();
	void CreateDrawingBuffers(size_t vertexBufferSize, size_t indexBufferSize, size_t modelMatrixBufferSize);
	void CreateStagingBuffer(size_t bufferSize);
	void CreateBuffer(VkDeviceSize size, VkBufferUsageFlags usage, VkMemoryPropertyFlags properties, VkBuffer& buffer, VkDeviceMemory& bufferMemory);
	void LoadDrawingBuffers(VkBuffer& vertexBuffer, VkBuffer indexBuffer, VkBuffer modelMatrixBuffer, DrawData& drawData);
	void CopyBuffer(VkBuffer srcBuffer, VkBuffer dstBuffer, VkDeviceSize size);
};