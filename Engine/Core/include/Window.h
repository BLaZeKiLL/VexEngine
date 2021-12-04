#pragma once

#include <string>

struct GLFWwindow;

namespace VEX
{
	struct WindowConfig
	{
		const std::string& Title;
		const int Width;
		const int Height;
		const bool FullScreen;
	};

	class Window
	{
	public:
		Window(const WindowConfig& Config);
		~Window();

		void Init();
		void Update();

		void Close();
		bool ShouldClose();
		bool IsKeyPressed(int key);
	private:
		WindowConfig _Config;
		GLFWwindow* _Window;

		static void ResizeCallback(GLFWwindow* window, int width, int height);
	};
}
