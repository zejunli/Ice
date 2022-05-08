#include "Application.h"
#include "Ice/Events/ApplicationEvent.h"
#include "Ice/Log.h"

using namespace std;

namespace Ice 
{
	Application::Application()
	{

	}

	Application::~Application()
	{
			
	}

	void Application::Run()
	{
		WindowResizeEvent e(200, 100);

		if (e.IsInCategory(EventCategoryApplication))
		{
			ICE_TRACE(e);
		}

		if (e.IsInCategory(EventCategoryInput))
		{
			ICE_TRACE(e);
		}


		while (true);
	}

}