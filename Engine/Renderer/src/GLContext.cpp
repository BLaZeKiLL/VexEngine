#include "Vex/Libs.h"
#include "Vex/Core.h"

#include "GLContext.h"

namespace VEX
{
	GLContext::~GLContext()
	{
		glDeleteVertexArrays(vaos.size(), vaos.data());
		glDeleteBuffers(vbos.size(), vbos.data());
		glDeleteBuffers(vbos.size(), vbos.data());

		VEX_LOG_INFO("OpenGL Context Cleaned");
	}

	unsigned int GLContext::CreateVao()
	{
		unsigned int vao = 0;
		// Does support multiple
		glGenVertexArrays(1, &vao);

		VEX_LOG_TRACE("Vertex Array : %d Created", vao);

		vaos.push_back(vao);
		return vao;
	}

	unsigned int GLContext::CreateVbo()
	{
		unsigned int vbo = 0;
		// Does support multiple
		glGenBuffers(1, &vbo);

		VEX_LOG_TRACE("Vertex Buffer : %d Created", vbo);

		vbos.push_back(vbo);
		return vbo;
	}

	unsigned int GLContext::CreateIbo()
	{
		unsigned int ibo = 0;
		// Does support multiple
		glGenBuffers(1, &ibo);

		VEX_LOG_TRACE("Index Buffer : %d Created", ibo);

		ibos.push_back(ibo);
		return ibo;
	}

	void GLContext::BindVao(const unsigned int id)
	{
		glBindVertexArray(id);
		VEX_LOG_TRACE("Vertex Array : %d Bound", id);
	}

	void GLContext::BindVbo(const unsigned int id)
	{
		glBindBuffer(GL_ARRAY_BUFFER, id);
		VEX_LOG_TRACE("Vertex Buffer : %d Bound", id);
	}

	void GLContext::BindIbo(const unsigned int id)
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, id);
		VEX_LOG_TRACE("Index Buffer : %d Bound", id);
	}

	void GLContext::SetDataBuffer(const unsigned int id, const unsigned int attribute, const unsigned int size, const void* buffer)
	{
		BindVbo(id);

		glBufferData(GL_ARRAY_BUFFER, size, buffer, GL_STATIC_DRAW);

		glVertexAttribPointer(attribute, size, GL_FLOAT, false, 0, nullptr);

		VEX_LOG_TRACE("For Buffer : %d, Attribute : %d, Data Buffer of size : %d has been set", id, attribute, size);

		BindVbo(0);
	}

	void GLContext::SetIndexBuffer(const unsigned int id, const unsigned int size, const void* buffer)
	{
		BindIbo(id);

		glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, buffer, GL_STATIC_DRAW);

		VEX_LOG_TRACE("For Buffer : %d, Index Buffer of size : %d has been set", id, size);

		BindIbo(0);
	}
}
