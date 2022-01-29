#pragma once

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <optional>

namespace Voxls
{
	struct QueueFamilyIndices {
		std::optional<uint32_t> graphicsFamily;

		bool isValue() {
			return graphicsFamily.has_value();
		}
	};

	class Vulkan
	{
	public:
		void OnDestroy();

		VkInstance& GetInstance() { return m_VkInstance; }

		static Vulkan* Create(const char* title);
	private:
		Vulkan(const char* title);

		VkInstance m_VkInstance;
		VkPhysicalDevice m_PhysicalDevice;

		bool checkValidationLayers();

		void selectPhysicalDevice();
		bool isPhysicalDeviceValid(VkPhysicalDevice device);
		QueueFamilyIndices findQueueFamilies(VkPhysicalDevice device);
	};
}