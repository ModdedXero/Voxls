#pragma once

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <optional>

namespace Voxls
{
	struct QueueFamilyIndices {
		std::optional<uint32_t> graphicsFamily;
		std::optional<uint32_t> presentFamily;

		bool isValue() {
			return graphicsFamily.has_value() && presentFamily.has_value();
		}
	};

	struct SwapChainSupportDetails {
		VkSurfaceCapabilitiesKHR capabilities;
		std::vector<VkSurfaceFormatKHR> formats;
		std::vector<VkPresentModeKHR> presentModes;
	};

	class Vulkan
	{
	public:
		void OnDestroy();

		VkInstance& GetInstance() { return m_Instance; }

		static Vulkan* Create(const char* title, GLFWwindow* window);
	private:
		Vulkan(const char* title, GLFWwindow* window);

		const char* m_Title;
		GLFWwindow* m_Window;

		VkInstance m_Instance;
		VkSurfaceKHR m_Surface;
		VkPhysicalDevice m_PhysicalDevice;
		VkDevice m_LogicalDevice;
		VkQueue m_GraphicsQueue;
		VkQueue m_PresentQueue;

		void createInstance();
		void createSurface();

		bool checkValidationLayers();

		void selectPhysicalDevice();
		bool isPhysicalDeviceValid(VkPhysicalDevice device);
		bool checkDeviceExtensionSupport(VkPhysicalDevice device);
		QueueFamilyIndices findQueueFamilies(VkPhysicalDevice device);
		SwapChainSupportDetails querySwapChainSupport(VkPhysicalDevice device);

		void createLogicalDevice();
	};
}