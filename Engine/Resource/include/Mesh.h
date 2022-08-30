#pragma once

namespace VEX
{
	class VertexBufferLayout;
	class VertexBuffer;
	class IndexBuffer;
	class VertexArray;

	class Mesh final
	{
	private:
		VertexBufferLayout& m_layout;

		unsigned int m_VertexCount;
		unsigned int m_IndexCount;

		VertexBuffer* m_VB;
		IndexBuffer* m_IB;
		VertexArray* m_VA;

	public:
		Mesh(VertexBufferLayout& layout, const void* vertices, unsigned int vcount, const unsigned int* indices, unsigned int icount);
		~Mesh();

		void Bind() const;
		void Unbind() const;

		inline const unsigned int GetVertexSize() const { return m_VertexCount; }
		inline const unsigned int GetIndexCount() const { return m_IndexCount; }

	};
}
