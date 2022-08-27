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

        float m_LastTime;
	public:
		Window(const WindowConfig& Config);
		~Window();

		void PreRender() const;
		void PostRender();

		void Close() const;
		bool ShouldClose() const;

		int GetKeyAction(int key) const;
        int GetMouseAction(int key) const;

        void LockCursor(bool value) const;
        bool IsCursorLocked() const;
        void GetCursorPosition(double* xpos, double* ypos) const;

        float GetTime() const;
        float GetDeltaTime() const;
	};
}
