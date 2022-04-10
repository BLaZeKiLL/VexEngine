#pragma once

struct GLFWwindow;

namespace VEX
{
	// TODO : Move To Build Time Define
	enum class Platform
	{
		OPENGL,
		VULKAN
	};

	bool InitializePlatform(Platform platform, GLFWwindow* window);
}
