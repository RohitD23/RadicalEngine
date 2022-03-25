#pragma once
#include "Core.h"
#include "Window.h"
#include "Events/Event.h"
#include "Events/ApplicationEvent.h"

namespace Radical 
{
	class RL_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);

	private:
		bool OnWindowClose(WindowClosedEvent& e);

		std::unique_ptr <Window> m_Window;
		bool m_Running = true;
	};

	//To Create Application at client side
	Application* CreateApplication();
}

