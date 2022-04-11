#pragma once

namespace VEX
{
	class VertexBuffer;
	class VertexBufferLayout;

	class VertexArray final
	{
	private:
		unsigned int m_RendererId;
	public:
		VertexArray();
		~VertexArray();

		void AddBuffer(const VertexBuffer* vb, const VertexBufferLayout& layout) const;

		void Bind() const;
		void Unbind() const;
	};
}
