#include "Vex/Vendor.h"

#include "OpenGL/VertexBufferLayout.h"

namespace VEX
{
	unsigned int VertexBufferElement::GetSizeOfType(const unsigned int type)
	{
		switch (type)
		{
		case GL_FLOAT: return sizeof(GLfloat);
		case GL_UNSIGNED_INT: return sizeof(GLuint);
		case GL_UNSIGNED_BYTE: return sizeof(GLubyte);
		}
		assert(false);
		return 0;
	}

	VertexBufferLayout::VertexBufferLayout() : m_Stride(0)
	{
	}

	template <>
	void VertexBufferLayout::Push<float>(const unsigned int count)
	{
		m_Elements.push_back({ GL_FLOAT, count, GL_FALSE });
		m_Stride += count * VertexBufferElement::GetSizeOfType(GL_FLOAT);
	}

	template <>
	void VertexBufferLayout::Push<unsigned int>(const unsigned int count)
	{
		m_Elements.push_back({ GL_UNSIGNED_INT, count, GL_FALSE });
		m_Stride += count * VertexBufferElement::GetSizeOfType(GL_UNSIGNED_INT);
	}

	template <>
	void VertexBufferLayout::Push<unsigned char>(const unsigned int count)
	{
		m_Elements.push_back({ GL_UNSIGNED_BYTE, count, GL_TRUE });
		m_Stride += count * VertexBufferElement::GetSizeOfType(GL_UNSIGNED_BYTE);
	}
}
