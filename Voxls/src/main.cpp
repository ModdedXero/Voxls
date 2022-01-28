#include "Application.h"

int main()
{
	Voxls::Application* app = new Voxls::Application();
	app->Run();
	delete app;
}