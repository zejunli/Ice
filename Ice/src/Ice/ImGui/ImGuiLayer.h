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

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnImGuiRender() override;

		void Begin();
		void End();
	
	private:
		float m_Time = 0.0f;

	};
}
