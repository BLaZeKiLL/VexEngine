#include "Vex/Vendor.h"

#include "Logger.h"
#include "OpenGL/OpenGLExtensions.h"

bool VEX::InitializeOpenGL(GLFWwindow* window)
{
	if (!gladLoadGLLoader(reinterpret_cast<GLADloadproc>(glfwGetProcAddress)))
	{
		VEX_LOG_ERROR("Failed To Initialize GLAD");
		return false;
	}

	// Error Handling
	glEnable(GL_DEBUG_OUTPUT);

#ifdef VEX_WINDOWS // Debug message call back is only supported on OpenGl 4.3+
    glDebugMessageCallback(MessageCallback, nullptr);
#endif

	// Blending
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    // Depth buffer
	glEnable(GL_DEPTH_TEST);

	glfwSetFramebufferSizeCallback(window, ResizeCallback);

	VEX_LOG_INFO("OpenGL Initialized");

	return true;
}

void VEX::ResizeCallback(GLFWwindow* window, const int width, const int height)
{
	glViewport(0, 0, width, height);
}

void VEX::MessageCallback(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar* message, const void* param)
{
	switch (severity)
	{
	case GL_DEBUG_SEVERITY_HIGH:
		VEX_LOG_ERROR("[OPENGL: {} type = {}] message = {}\n", id, type, message);
		break;
	case GL_DEBUG_SEVERITY_MEDIUM:
		VEX_LOG_WARN("[OPENGL: {} type = {}] message = {}\n", id, type, message);
		break;
	case GL_DEBUG_SEVERITY_LOW:
		VEX_LOG_INFO("[OPENGL: {} type = {}] message = {}\n", id, type, message);
		break;
	case GL_DEBUG_SEVERITY_NOTIFICATION:
		VEX_LOG_DEBUG("[OPENGL: {} type = {}] message = {}\n", id, type, message);
		break;
	}
}
