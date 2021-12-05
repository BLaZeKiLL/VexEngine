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
		void Update() const;

		void Close() const;
		bool ShouldClose() const;
		bool IsKeyPressed(int key) const;
	private:
		WindowConfig Config;
		GLFWwindow* _Window;

		static void ResizeCallback(GLFWwindow* window, int width, int height);
	};
}
