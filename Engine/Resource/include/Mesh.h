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

		unsigned int m_VertexSize;
		unsigned int m_IndexCount;

		VertexBuffer* m_VB;
		IndexBuffer* m_IB;
		VertexArray* m_VA;
	public:
		Mesh(VertexBufferLayout& layout, const void* vertices, unsigned int size, const unsigned int* indices, unsigned int count);
		~Mesh();

		void Bind() const;
		void Unbind() const;

		inline unsigned int GetVertexSize() const { return m_VertexSize; }
		inline unsigned int GetIndexCount() const { return m_IndexCount; }
	};
}
