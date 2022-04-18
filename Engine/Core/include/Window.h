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

	class Window final
	{
	private:
		WindowConfig m_Config;
		GLFWwindow* m_Window;
	public:
		Window(const WindowConfig& Config);
		~Window();

		void PreRender() const;
		void PostRender() const;

		void Close() const;
		bool ShouldClose() const;
		bool IsKeyPressed(int key) const;
	};
}
