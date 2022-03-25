#pragma once

#ifdef RL_PLATFORM_WINDOWS

extern Radical::Application* Radical::CreateApplication();

int main(int argc, char** argv)
{
	Radical::Log::Init();
	RL_CORE_TRACE("Initialized Log");
	int a = 5;
	RL_INFO("Hello! Var = {0}", a);

	auto app = Radical::CreateApplication();
	app->Run();
	delete app;
}

#endif // RL_PLATFROM_WINDOWS
