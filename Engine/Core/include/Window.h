#pragma once

#include <string>

class GLFWwindow;

namespace VEX
{
	class Window
	{
	public:
		struct Config
		{
			const std::string& Title;
			const int Width;
			const int Height;
			const bool FullScreen;
		};

		Window(const Config& Config);
		~Window();

		void Init();
		void Update();

		void Close();
		bool ShouldClose();
		bool IsKeyPressed(int key);
	private:
		Config _Config;
		GLFWwindow* _Window;

		static void ResizeCallback(GLFWwindow* window, int width, int height);
	};
}
