#include "Logger.h"

#include "Platform/Platform.h"
#include "Platform/OpenGL/OpenGL.h"

bool VEX::InitializePlatform(const Platform platform, GLFWwindow* window)
{
	switch (platform) {
		case Platform::OPENGL:
			return InitializeOpenGL(window);
		case Platform::VULKAN:
			VEX_LOG_ERROR("Platform Not Implemented");
			return false;
		default:
			VEX_LOG_ERROR("Unidentified Platform");
			return false;
	}
}
