#include <Radical.h>

class ExampleLayer : public Radical::Layer
{
public:
	ExampleLayer()
		: Layer("Example") {}

	void OnUpdate() override
	{
		RL_INFO("ExampleLayer::Update");
	}

	void OnEvent(Radical::Event& event) override
	{
		RL_TRACE("{0}", event);
	}
};

class SandBox : public Radical::Application
{
public:
	SandBox() { PushLayer(new ExampleLayer()); }

	~SandBox() {}
};

Radical::Application* Radical::CreateApplication()
{
	return new SandBox();
}