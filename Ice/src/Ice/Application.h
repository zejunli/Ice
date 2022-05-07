#pragma once
#include "Core.h"

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
