#include "Vex/Vendor.h"

#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>

#include "Window.h"
#include "Logger.h"
#include "OpenGL/OpenGL.h"

namespace VEX
{
	Window::Window(const WindowConfig& Config) : m_Config(Config)
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

		IMGUI_CHECKVERSION();
		ImGui::CreateContext();
		ImGui::StyleColorsDark();

		ImGui_ImplGlfw_InitForOpenGL(m_Window, true);
		ImGui_ImplOpenGL3_Init("#version 450");

		InitializeOpenGL(m_Window);
	}

	Window::~Window()
	{
		ImGui_ImplOpenGL3_Shutdown();
	    ImGui_ImplGlfw_Shutdown();
	    ImGui::DestroyContext();

		glfwDestroyWindow(m_Window);
		glfwTerminate();
	}

	void Window::PreRender() const
	{
		ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();
	}

	void Window::PostRender() const
	{
		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

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
