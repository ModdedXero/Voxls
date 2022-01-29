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

		m_Window = glfwCreateWindow(props.Width, props.Height, props.Title, NULL, NULL);
		if (!m_Window)
		{
			// Log Error
			return;
		}
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
		glfwDestroyWindow(m_Window);
		glfwTerminate();
	}

<<<<<<< HEAD
<<<<<<< HEAD
=======
=======
>>>>>>> 6510e0961814f9b1a5382281f59f96561e9d21b1
	bool Window::IsRunning()
	{

	}

<<<<<<< HEAD
>>>>>>> 6510e0961814f9b1a5382281f59f96561e9d21b1
=======
>>>>>>> 6510e0961814f9b1a5382281f59f96561e9d21b1
	Window* Window::Create(const WindowProps& props)
	{
		return new Window(props);
	}
}