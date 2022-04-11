#include <glm/gtc/type_ptr.hpp>


#include "Logger.h"

#include "Platform/OpenGL/Shader.h"

namespace VEX
{
	Shader::Shader(const unsigned int id) : m_RendererId(id)
	{
	}

	Shader::~Shader()
	{
		glDeleteProgram(m_RendererId);
	}

	void Shader::Bind() const
	{
		glUseProgram(m_RendererId);
	}

	void Shader::Unbind() const
	{
		glUseProgram(0);
	}

	void Shader::SetUniform4fv(const std::string& name, const glm::vec4 value) const
	{
		glUniform4fv(GetUniformLocation(name), 1, value_ptr(value));
	}

	int Shader::GetUniformLocation(const std::string& name) const
	{
		const int location = glGetUniformLocation(m_RendererId, name.c_str());

		if (location == -1)
		{
			VEX_LOG_ERROR("{} uniform not found", name);
		}

		return location;
	}
}
