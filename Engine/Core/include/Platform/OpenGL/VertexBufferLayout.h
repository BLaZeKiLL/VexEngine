#pragma once

#include <vector>

namespace VEX
{
	struct VertexBufferElement final
	{
		unsigned int type;
		unsigned int count;
		unsigned int normalized;

		static unsigned int GetSizeOfType(unsigned int type);
	};

	class VertexBufferLayout final
	{
	private:
		unsigned int m_Stride;
		std::vector<VertexBufferElement> m_Elements;
	public:
		VertexBufferLayout();

		inline unsigned int GetStride() const { return m_Stride; }
		inline const std::vector<VertexBufferElement>& GetElements() const { return m_Elements; }

		template<typename T>
		void Push(unsigned int count) { static_assert(false); }

		template<>
		void Push<float>(unsigned int count);

		template<>
		void Push<unsigned int>(unsigned int count);

		template<>
		void Push<unsigned char>(unsigned int count);
	};
}
