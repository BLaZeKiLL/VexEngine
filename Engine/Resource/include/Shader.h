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
		explicit Shader(unsigned int id);
		~Shader();

		void Bind() const;
		void Unbind() const;

		// Set Uniforms
		void SetUniform1i(const std::string& name, int value);
		void SetUniform2i(const std::string& name, glm::ivec2 value);
		void SetUniform3i(const std::string& name, glm::ivec3 value);
		void SetUniform4i(const std::string& name, glm::ivec4 value);

		void SetUniform1f(const std::string& name, float value);
		void SetUniform2f(const std::string& name, glm::vec2 value);
		void SetUniform3f(const std::string& name, glm::vec3 value);
		void SetUniform4f(const std::string& name, glm::vec4 value);

		void SetUniformMat4f(const std::string& name, glm::mat4 value);
	private:
		int GetUniformLocation(const std::string& name);
	};
}
