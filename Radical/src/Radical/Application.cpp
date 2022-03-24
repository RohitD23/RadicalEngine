#include "Application.h"

#include "Radical/Events/ApplicationEvent.h"
#include "Radical/Log.h"

namespace Radical
{
	Application::Application()
	{
	}

	Application::~Application()
	{
	}

	void Application::Run()
	{
		WindowResizeEvent e(1280, 720);
		RL_TRACE(e);
		while (true);
	}
}