#pragma once

#include <vector>

namespace VEX
{
	class GLContext final
	{
	private:
		std::vector<unsigned int> vaos;
		std::vector<unsigned int> vbos;
		std::vector<unsigned int> ibos;

	public:
		~GLContext();

		unsigned int CreateVao();
		unsigned int CreateVbo();
		unsigned int CreateIbo();

		void BindVao(unsigned int id);
		void BindVbo(unsigned int id);
		void BindIbo(unsigned int id);

		void SetDataBuffer(unsigned int id, unsigned int attribute, unsigned int size, const void* buffer);
		void SetIndexBuffer(unsigned int id, unsigned int size, const void* buffer);
	};
}
