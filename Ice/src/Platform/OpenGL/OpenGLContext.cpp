#include "icepch.h"
#include "OpenGLContext.h"


namespace Ice
{
	OpenGLContext::OpenGLContext(GLFWwindow* windowHandle) 
		: m_WindowHandle(windowHandle)
	{
		ICE_CORE_ASSERT(windowHandle, "Window handle is NULL!");
	}


	void OpenGLContext::Init()
	{
		glfwMakeContextCurrent(m_WindowHandle);

		// init glad
		int success = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		ICE_CORE_ASSERT(success, "Failed to initialize GLAD!");
		
		ICE_CORE_INFO("OpenGL Info: ");
		ICE_CORE_INFO("  Vendor: {0}", glGetString(GL_VENDOR));
		ICE_CORE_INFO("  Renderer: {0}", glGetString(GL_RENDERER));
		ICE_CORE_INFO("  Version: {0}", glGetString(GL_VERSION));
	}


	void OpenGLContext::SwapBuffer()
	{
		glfwSwapBuffers(m_WindowHandle);
	}
}