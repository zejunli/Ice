#pragma once

#include "Ice/Core.h"
#include "Ice/Events/Event.h"
#include "Window.h"


namespace Ice
{
	class ICE_API Application
	{
	public:
		Application();
		virtual ~Application();
		
		void Run();

	private:
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
	};
	
	// to be defined in the client
	Application* CreateApplication();

}
