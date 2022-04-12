#pragma once

#include <string>

namespace VEX
{
	class Shader final
	{
	private:
		unsigned int m_RendererId;
	public:
		Shader(unsigned int id);
		~Shader();

		void Bind() const;
		void Unbind() const;

		void SetUniform4f(const std::string& name, const glm::vec4 value) const;
	private:
		int GetUniformLocation(const std::string& name) const;
	};
}