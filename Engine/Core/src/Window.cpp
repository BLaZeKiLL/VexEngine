#define GLFW_INCLUDE_NONE

#include <GLFW/glfw3.h>
#include <glad/glad.h>

#include "Window.h"
#include "Logger.h"

namespace VEX
{
	Window::Window(const WindowConfig& Config) : _Config(Config)
	{
	}

	Window::~Window()
	{
		glfwDestroyWindow(_Window);
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
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
		glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GLFW_TRUE);

		_Window = glfwCreateWindow(
			_Config.Width,
			_Config.Height,
			_Config.Title.c_str(), _Config.FullScreen ? glfwGetPrimaryMonitor() : nullptr,
			nullptr
		);

		if (!_Window)
		{
			VEX_LOG_ERROR("GLFW Failed To Create A Window");
			return;
		}

		glfwSetFramebufferSizeCallback(_Window, Window::ResizeCallback);

		glfwMakeContextCurrent(_Window);

		glfwSwapInterval(1); // V-Sync

		glfwShowWindow(_Window);

		if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress))
		{
			VEX_LOG_ERROR("Failed To Initialize GLAD");
			return;
		}

		VEX_LOG_INFO("OpenGL 3.3 Initialized");
	}

	void Window::Update()
	{
		glfwSwapBuffers(_Window);
		glfwPollEvents();
	}

	void Window::Close()
	{
		glfwSetWindowShouldClose(_Window, GLFW_TRUE);
	}

	bool Window::ShouldClose()
	{
		return glfwWindowShouldClose(_Window);
	}

	bool Window::IsKeyPressed(int key)
	{
		return glfwGetKey(_Window, key) == GLFW_PRESS;
	}

	void Window::ResizeCallback(GLFWwindow* window, int width, int height)
	{
		glViewport(0, 0, width, height);
	}
}
