#pragma once

#include "Ice/Core.h"
#include "Ice/Events/Event.h"
#include "Ice/Events/ApplicationEvent.h"
#include "Window.h"
#include "Ice/LayerStack.h"



namespace Ice
{

	class ICE_API Application
	{
	public:
		Application();
		virtual ~Application();
		
		void Run();
		
		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* overlay);
	private:
		bool OnWindowClose(WindowCloseEvent& e);
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;

		LayerStack m_LayerStack;
	};
	
	// to be defined in the client
	Application* CreateApplication();

}
