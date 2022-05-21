#include <Ice.h>

class ExampleLayer : public Ice::Layer
{
public:
	ExampleLayer() : Layer("this is example layer") {}

	void OnUpdate() override
	{
		ICE_INFO("ExampleLayer::Update");
	}

	void OnEvent(Ice::Event& e) override
	{
		ICE_TRACE("{0}", e);
	}
};



class Sandbox : public Ice::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
	}

	~Sandbox()
	{

	}

};


Ice::Application* Ice::CreateApplication() {
	return new Sandbox();
}