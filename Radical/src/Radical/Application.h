#pragma once
#include "Radical/Core.h"
#include "Radical/Window.h"
#include "Radical/LayerStack.h"
#include "Radical/Events/Event.h"
#include "Radical/Events/ApplicationEvent.h"

namespace Radical 
{
	class RL_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* overlay);

	private:
		bool OnWindowClose(WindowClosedEvent& e);

		std::unique_ptr <Window> m_Window;
		bool m_Running = true;
		LayerStack m_LayerStack;
	};

	//To Create Application at client side
	Application* CreateApplication();
}

