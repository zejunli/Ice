#pragma once

#include "Ice/Layer.h"
#include "Ice/Events/KeyEvent.h"
#include "Ice/Events/MouseEvent.h"
#include "Ice/Events/ApplicationEvent.h"

namespace Ice
{
	class ICE_API ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();

		void OnAttach();
		void OnDetach();
		void OnUpdate();
		void OnEvent(Event& e);

	private:
		bool OnMouseButtonPressedEvent(MouseButtonPressedEvent& event);
		bool OnMouseButtonReleasedEvent(MouseButtonReleasedEvent& event);
		bool OnMouseMovedEvent(MouseMovedEvent& event);
		bool OnMouseScrolledEvent(MouseScrolledEvent& event);
		bool OnKeyPressedEvent(KeyPressedEvent& event);
		bool OnKeyReleasedEvent(KeyReleasedEvent& event);
		//bool OnKeyTypedEvent(KeyTypedEvent& event);
		bool onWindowResizedEvent(WindowResizeEvent& event);

	private:
		float m_Time = 0.0f;

	};
}
