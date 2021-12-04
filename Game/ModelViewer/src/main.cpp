#include "Core.h"

#include <GLFW/glfw3.h>
#include <glad/glad.h>

int main(int, char**)
{
	VEX::Logger::Init();

	// string literals in c++ are const char * NOT strings
	const std::string title = "Model Viewer";

	const auto config = VEX::WindowConfig {
		title, 1280, 720, false
	};

	const auto window = new VEX::Window(config);

	window->Init();

	while (!window->ShouldClose())
	{
		if (window->IsKeyPressed(GLFW_KEY_ESCAPE)) {
			window->Close();
		}

		glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		window->Update();
	}

	delete window;
	return 0;
}
