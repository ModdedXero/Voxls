#include "Application.h"

namespace Voxls
{
	Application::Application()
	{
		m_Window = Window::Create(WindowProps());
	}

	Application::~Application()
	{

	}

	void Application::Run()
	{
		while (m_Window->IsRunning())
		{
			m_Window->OnUpdate();
			m_Window->OnRender();
		}
	}
}