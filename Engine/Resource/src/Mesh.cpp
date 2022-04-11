#include "Mesh.h"

#include "Vex/OpenGL.h"

namespace VEX
{
	Mesh::Mesh(VertexBufferLayout& layout, const void* vertices, const unsigned int size, const unsigned int* indices, const unsigned int count) :
		m_layout(layout), m_VertexSize(size), m_IndexCount(count),
		m_VB(new VertexBuffer(vertices, m_VertexSize)),
		m_IB(new IndexBuffer(indices, m_IndexCount)),
		m_VA(new VertexArray())
	{
		m_VA->AddBuffer(m_VB, layout);
	}

	Mesh::~Mesh()
	{
		delete m_VB;
		delete m_IB;
		delete m_VA;
	}

	void Mesh::Bind() const
	{
		m_VA->Bind();
		m_IB->Bind();
	}

	void Mesh::Unbind() const
	{
		m_IB->Unbind();
		m_VA->Unbind();
	}
}
