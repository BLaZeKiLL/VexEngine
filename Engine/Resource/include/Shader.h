#pragma once

#include <string>
#include <unordered_map>

#include "Vex/Math.h"

namespace VEX
{
	class Shader final
	{
	private:
		unsigned int m_RendererId;
		std::unordered_map<std::string, int> m_UniformLocationCache;
	public:
		Shader(unsigned int id);
		~Shader();

		void Bind() const;
		void Unbind() const;

		// Set Uniforms
		void SetUniform1i(const std::string& name, const glm::ivec1 value);
		void SetUniform1f(const std::string& name, const glm::vec1 value);
		void SetUniform4f(const std::string& name, const glm::vec4 value);
		void SetUniformMat4f(const std::string& name, const glm::mat4 value);
	private:
		int GetUniformLocation(const std::string& name);
	};
}
