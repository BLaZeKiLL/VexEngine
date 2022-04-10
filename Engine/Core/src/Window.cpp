#include "CoreLibs.h"

#include "Window.h"
#include "Logger.h"

#include "Platform/Platform.h"

namespace VEX
{
	Window::Window(const WindowConfig& Config) : m_Config(Config)
	{
	}

	Window::~Window()
	{
		glfwDestroyWindow(m_Window);
		glfwTerminate();
	}

	void Window::Init()
	{
		if (!glfwInit())
		{
			VEX_LOG_ERROR("GLFW Failed To Initialize");
			return; // throw runtime exception
		}

		glfwDefaultWindowHints();
		glfwWindowHint(GLFW_VISIBLE, GLFW_FALSE);
		glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
		glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GLFW_TRUE);

		m_Window = glfwCreateWindow(
			m_Config.Width,
			m_Config.Height,
			m_Config.Title.c_str(), m_Config.FullScreen ? glfwGetPrimaryMonitor() : nullptr,
			nullptr
		);

		if (!m_Window)
		{
			VEX_LOG_ERROR("GLFW Failed To Create A Window");
			return;
		}

		glfwMakeContextCurrent(m_Window);

		glfwSwapInterval(1); // V-Sync

		glfwShowWindow(m_Window);

		InitializePlatform(Platform::OPENGL, m_Window);
	}

	void Window::Update() const
	{
		glfwSwapBuffers(m_Window);
		glfwPollEvents();
	}

	void Window::Close() const
	{
		glfwSetWindowShouldClose(m_Window, GLFW_TRUE);
	}

	bool Window::ShouldClose() const
	{
		return glfwWindowShouldClose(m_Window);
	}

	bool Window::IsKeyPressed(const int key) const
	{
		return glfwGetKey(m_Window, key) == GLFW_PRESS;
	}
}
