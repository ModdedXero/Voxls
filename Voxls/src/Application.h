#pragma once

#include "Window.h"

namespace Voxls
{
	class Application
	{
	public:
		Application();
		virtual ~Application();

		virtual void Run();

		virtual Window& GetWindow() { return *m_Window; }
	private:
		Window* m_Window;
	};
}