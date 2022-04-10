#pragma once

#include "VertexBuffer.h"
#include "VertexBufferLayout.h"
#include "IndexBuffer.h"
#include "VertexArray.h"

struct GLFWwindow;

namespace VEX
{
	bool InitializeOpenGL(GLFWwindow* window);
	void ResizeCallback(GLFWwindow* window, int width, int height);
	void MessageCallback(unsigned source, unsigned type, unsigned id, unsigned severity, int length, const char* message, const void* param);
}
