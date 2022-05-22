#include "icepch.h"
#include "ImGuiLayer.h"
#include "imgui.h"

#include "Platform/OpenGL/imgui_impl_opengl3.h"
#include "Platform/OpenGL/imgui_impl_glfw.h"
#include <GLFW/glfw3.h>
#include "Ice/Application.h"
#include "Platform/Windows/WindowsWindow.h"

namespace Ice
{	

	ImGuiLayer::ImGuiLayer() : Layer("ImGuiLayer")
	{

	}


	ImGuiLayer::~ImGuiLayer()
	{

	}
	
	
	//void ImGuiLayer::OnAttach()
	//{
	//	// init ImGui
	//	ImGui::CreateContext();
	//	ImGui::StyleColorsDark();
	//	
	//	ImGuiIO& io = ImGui::GetIO();
	//	
	//	io.KeyMap[ImGuiKey_Tab] = GLFW_KEY_TAB;
	//	io.KeyMap[ImGuiKey_LeftArrow] = GLFW_KEY_LEFT;
	//	io.KeyMap[ImGuiKey_RightArrow] = GLFW_KEY_RIGHT;
	//	io.KeyMap[ImGuiKey_UpArrow] = GLFW_KEY_UP;
	//	io.KeyMap[ImGuiKey_DownArrow] = GLFW_KEY_DOWN;
	//	io.KeyMap[ImGuiKey_PageUp] = GLFW_KEY_PAGE_UP;
	//	io.KeyMap[ImGuiKey_PageDown] = GLFW_KEY_PAGE_DOWN;
	//	io.KeyMap[ImGuiKey_Home] = GLFW_KEY_HOME;
	//	io.KeyMap[ImGuiKey_End] = GLFW_KEY_END;
	//	io.KeyMap[ImGuiKey_Insert] = GLFW_KEY_INSERT;
	//	io.KeyMap[ImGuiKey_Delete] = GLFW_KEY_DELETE;
	//	io.KeyMap[ImGuiKey_Backspace] = GLFW_KEY_BACKSPACE;
	//	io.KeyMap[ImGuiKey_Space] = GLFW_KEY_SPACE;
	//	io.KeyMap[ImGuiKey_Enter] = GLFW_KEY_ENTER;
	//	io.KeyMap[ImGuiKey_Escape] = GLFW_KEY_ESCAPE;
	//	io.KeyMap[ImGuiKey_KeyPadEnter] = GLFW_KEY_KP_ENTER;
	//	io.KeyMap[ImGuiKey_A] = GLFW_KEY_A;
	//	io.KeyMap[ImGuiKey_C] = GLFW_KEY_C;
	//	io.KeyMap[ImGuiKey_V] = GLFW_KEY_V;
	//	io.KeyMap[ImGuiKey_X] = GLFW_KEY_X;
	//	io.KeyMap[ImGuiKey_Y] = GLFW_KEY_Y;
	//	io.KeyMap[ImGuiKey_Z] = GLFW_KEY_Z;

	//	ImGui_ImplOpenGL3_Init("#version 410");
	//}


	//void ImGuiLayer::OnDetach()
	//{

	//}


	//void ImGuiLayer::OnUpdate()
	//{

	//	ICE_CORE_INFO("Zejun");
	//	ImGuiIO& io = ImGui::GetIO();
	//	Application& app = Application::Get();
	//	io.DisplaySize = ImVec2(app.GetWindow().GetWidth(), app.GetWindow().GetHeight());

	//	float time = (float)glfwGetTime();
	//	io.DeltaTime = m_Time > 0.0 ? (time - m_Time) : (1.0f / 60.0f);
	//	m_Time = time;

	//	ImGui_ImplOpenGL3_NewFrame();
	//	ImGui::NewFrame();
	//	
	//	static bool show = true;
	//	ImGui::ShowDemoWindow(&show);

	//	ImGui::Render();
	//	ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
	//}


	//void ImGuiLayer::OnEvent(Event& event)
	//{

	//}

	void ImGuiLayer::OnAttach()
	{
		ImGui::CreateContext();
		ImGui::StyleColorsDark();

		ImGuiIO& io = ImGui::GetIO();
		io.BackendFlags |= ImGuiBackendFlags_HasMouseCursors;
		io.BackendFlags |= ImGuiBackendFlags_HasSetMousePos;

		// TEMPORARY: should eventually use Hazel key codes
		io.KeyMap[ImGuiKey_Tab] = GLFW_KEY_TAB;
		io.KeyMap[ImGuiKey_LeftArrow] = GLFW_KEY_LEFT;
		io.KeyMap[ImGuiKey_RightArrow] = GLFW_KEY_RIGHT;
		io.KeyMap[ImGuiKey_UpArrow] = GLFW_KEY_UP;
		io.KeyMap[ImGuiKey_DownArrow] = GLFW_KEY_DOWN;
		io.KeyMap[ImGuiKey_PageUp] = GLFW_KEY_PAGE_UP;
		io.KeyMap[ImGuiKey_PageDown] = GLFW_KEY_PAGE_DOWN;
		io.KeyMap[ImGuiKey_Home] = GLFW_KEY_HOME;
		io.KeyMap[ImGuiKey_End] = GLFW_KEY_END;
		io.KeyMap[ImGuiKey_Insert] = GLFW_KEY_INSERT;
		io.KeyMap[ImGuiKey_Delete] = GLFW_KEY_DELETE;
		io.KeyMap[ImGuiKey_Backspace] = GLFW_KEY_BACKSPACE;
		io.KeyMap[ImGuiKey_Space] = GLFW_KEY_SPACE;
		io.KeyMap[ImGuiKey_Enter] = GLFW_KEY_ENTER;
		io.KeyMap[ImGuiKey_Escape] = GLFW_KEY_ESCAPE;
		io.KeyMap[ImGuiKey_A] = GLFW_KEY_A;
		io.KeyMap[ImGuiKey_C] = GLFW_KEY_C;
		io.KeyMap[ImGuiKey_V] = GLFW_KEY_V;
		io.KeyMap[ImGuiKey_X] = GLFW_KEY_X;
		io.KeyMap[ImGuiKey_Y] = GLFW_KEY_Y;
		io.KeyMap[ImGuiKey_Z] = GLFW_KEY_Z;
		

		//ImGui_ImplOpenGL3_Init("#version 410");
	}

	void ImGuiLayer::OnDetach()
	{

	}

	void ImGuiLayer::OnUpdate()
	{
		ImGuiIO& io = ImGui::GetIO();
		Application& app = Application::Get();
		io.DisplaySize = ImVec2(app.GetWindow()->GetWidth(), app.GetWindow()->GetHeight());
		
		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();

		float time = (float)glfwGetTime();
		io.DeltaTime = m_Time > 0.0f ? (time - m_Time) : (1.0f / 60.0f);
		m_Time = time;

		/*static bool show = true;
		ImGui::ShowDemoWindow(&show);*/

		// render your GUI
		ImGui::Begin("Demo window");
		ImGui::Button("Hello!");
		ImGui::End();
		
		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
	}

	void ImGuiLayer::OnEvent(Event& event)
	{

	}

	bool ImGuiLayer::OnMouseButtonPressedEvent(MouseButtonPressedEvent& event)
	{
		return false;
	}

	bool ImGuiLayer::OnMouseButtonReleasedEvent(MouseButtonReleasedEvent& event)
	{
		return false;
	}

	bool ImGuiLayer::OnMouseMovedEvent(MouseMovedEvent& event)
	{
		return false;
	}

	bool ImGuiLayer::OnMouseScrolledEvent(MouseScrolledEvent& event)
	{
		return false;
	}


	bool ImGuiLayer::OnKeyReleasedEvent(KeyReleasedEvent& event)
	{
		return false;
	}

	bool ImGuiLayer::onWindowResizedEvent(WindowResizeEvent& event)
	{
		return false;
	}

}