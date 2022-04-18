#include "Mesh.h"

#include "Vex/OpenGL.h"

namespace VEX
{
	Mesh::Mesh(VertexBufferLayout& layout, const void* vertices, const unsigned int vcount, const unsigned int* indices, const unsigned int icount) :
		m_layout(layout), m_VertexCount(vcount), m_IndexCount(icount),
		m_VB(new VertexBuffer(vertices, m_VertexCount * m_layout.GetStride())),
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
