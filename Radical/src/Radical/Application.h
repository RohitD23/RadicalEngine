#pragma once
#include "Core.h"

namespace Radical 
{
	class RL_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	//To Create Application at client side
	Application* CreateApplication();
}

