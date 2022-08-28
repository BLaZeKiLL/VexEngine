#include "Vex/Vendor.h"
#include "Vex/Core.h"

#include "Shader.h"

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

	void Shader::SetUniform1i(const std::string& name, const int value)
	{
		glUniform1i(GetUniformLocation(name), value);
	}

    void Shader::SetUniform2i(const std::string &name, const glm::ivec2 value)
    {
        glUniform2i(GetUniformLocation(name), value.x, value.y);
    }

    void Shader::SetUniform3i(const std::string &name, const glm::ivec3 value)
    {
        glUniform3i(GetUniformLocation(name), value.x, value.y, value.z);
    }

    void Shader::SetUniform4i(const std::string &name, const glm::ivec4 value)
    {
        glUniform4i(GetUniformLocation(name), value.x, value.y, value.z, value.w);
    }

    void Shader::SetUniform1f(const std::string& name, const float value)
    {
        glUniform1f(GetUniformLocation(name), value);
    }

    void Shader::SetUniform2f(const std::string &name, const glm::vec2 value)
    {
        glUniform2f(GetUniformLocation(name), value.x, value.y);
    }

    void Shader::SetUniform3f(const std::string &name, const glm::vec3 value)
    {
        glUniform3f(GetUniformLocation(name), value.x, value.y, value.z);
    }

	void Shader::SetUniform4f(const std::string& name, const glm::vec4 value)
	{
		glUniform4f(GetUniformLocation(name), value.x, value.y, value.z, value.w);
	}

	void Shader::SetUniformMat4f(const std::string& name, const glm::mat4 value)
	{
		glUniformMatrix4fv(GetUniformLocation(name), 1, GL_FALSE, glm::value_ptr(value));
	}

	int Shader::GetUniformLocation(const std::string& name)
	{
		if (m_UniformLocationCache.find(name) != m_UniformLocationCache.end())
			return m_UniformLocationCache[name];

		const int location = glGetUniformLocation(m_RendererId, name.c_str());

		if (location == -1)
		{
			VEX_LOG_WARN("{} uniform not found", name);
		}

		m_UniformLocationCache[name] = location;

		return location;
	}
}
