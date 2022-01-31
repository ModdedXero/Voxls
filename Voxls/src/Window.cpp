#include "Window.h"

namespace Voxls
{
	Window::Window(const WindowProps& props)
	{
		m_Data.Title = props.Title;
		m_Data.Width = props.Width;
		m_Data.Height = props.Height;

		if (!glfwInit())
		{
			// Log Error
			return;
		}

		glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
		glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

		m_Window = glfwCreateWindow(props.Width, props.Height, props.Title, NULL, NULL);
		if (!m_Window)
		{
			// Log Error
			return;
		}

		m_Vulkan = Vulkan::Create(props.Title, m_Window);
	}

	void Window::OnUpdate()
	{
		glfwPollEvents();
	}

	void Window::OnRender()
	{

	}

	void Window::OnDestory()
	{
		m_Vulkan->OnDestroy();

		glfwDestroyWindow(m_Window);
		glfwTerminate();
	}

	Window* Window::Create(const WindowProps& props)
	{
		return new Window(props);
	}
}