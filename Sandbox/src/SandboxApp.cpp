#include <Ice.h>


class ExampleLayer : public Ice::Layer
{
public:
	ExampleLayer() : Layer("this is example layer") {}

	void OnUpdate() override
	{
		//ICE_INFO("ExampleLayer::Update");
	}

	void OnEvent(Ice::Event& e) override
	{
		/*ICE_INFO("Example!!!");

		if (Ice::Input::IsKeyPressed(ICE_KEY_TAB))
			ICE_TRACE("It is pressed!");*/
	}
};



class Sandbox : public Ice::Application
{
public:
	Sandbox()
	{	
		PushLayer(new ExampleLayer());
		PushOverlay(new Ice::ImGuiLayer());
	}

	~Sandbox()
	{

	}

};


Ice::Application* Ice::CreateApplication() {
	return new Sandbox();
}