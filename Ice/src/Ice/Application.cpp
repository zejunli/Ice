#include "icepch.h"
#include "Application.h"
#include "Ice/Log.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

using namespace std;

namespace Ice 
{
#define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)

	Application::Application()
	{
		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallback(BIND_EVENT_FN(OnEvent));

	}


	Application::~Application()
	{
		
	}


	void Application::OnEvent(Event& e)
	{
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(OnWindowClose));


		for (auto it = m_LayerStack.end(); it != m_LayerStack.begin(); )
		{
			(*--it)->OnEvent(e);
			if (e.Handled)
				break;
		}
	}
	

	void Application::PushLayer(Layer* layer)
	{
		m_LayerStack.PushLayer(layer);
	}


	void Application::PushOverlay(Layer* overlay)
	{
		m_LayerStack.PushOverlay(overlay);
	}


	void Application::Run()
	{
		
		while (m_Running)
		{
			glClearColor(1, 1, 0, 1);
			glClear(GL_COLOR_BUFFER_BIT);
			m_Window->OnUpdate();

			for (Layer* layer : m_LayerStack)
				layer->OnUpdate();
		}
	}

	bool Application::OnWindowClose(WindowCloseEvent& e)
	{
		m_Running = false;
		return true;
	}

}