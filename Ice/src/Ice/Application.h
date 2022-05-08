#pragma once
#include "Core.h"
#include "Events/Event.h"

namespace Ice
{
	class ICE_API Application
	{
	public:
		Application();
		virtual ~Application();
		
		void Run();
	};
	
	// to be defined in the client
	Application* CreateApplication();

}
