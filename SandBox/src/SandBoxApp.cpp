#include <Radical.h>

class SandBox : public Radical::Application
{

};

Radical::Application* Radical::CreateApplication()
{
	return new SandBox();
}