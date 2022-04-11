#include <fstream>
#include <sstream>

#include "Vex/Core.h"
#include "Vex/Platform/OpenGL.h"

#include "ShaderCompiler.h"

namespace VEX
{
	Shader* ShaderCompiler::Compile(const std::string& path) const
	{
		const auto source = Preprocess(path);

		VEX_LOG_DEBUG(source.vertex);
		VEX_LOG_DEBUG(source.fragment);

		const unsigned int vid = CompileShader(GL_VERTEX_SHADER, source.vertex);
		const unsigned int fid = CompileShader(GL_FRAGMENT_SHADER, source.fragment);

		if (vid == 0 || fid == 0)
		{
			return nullptr;
		}

		const unsigned int program = glCreateProgram();

		glAttachShader(program, vid);
		glAttachShader(program, fid);
		glLinkProgram(program);

		int status;
		glGetProgramiv(program, GL_LINK_STATUS, &status);
		if(status != GL_TRUE)
		{
			int size;
			char message[1024];
			glGetProgramInfoLog(program, 1024, &size, message);

			VEX_LOG_ERROR("[SHADER] [LINKER ERROR] {}", message);

			return nullptr;
		}

		// Dev Only
		glValidateProgram(program);

		glDeleteShader(vid);
		glDeleteShader(fid);

		VEX_LOG_INFO("Shader Compiled : {}", path);

		return new Shader(program);
	}

	ShaderSource ShaderCompiler::Preprocess(const std::string& path) const
	{
		ShaderType type = ShaderType::NONE;
		std::string line;
		std::stringstream ss[2];
		std::ifstream stream(path);

		while (std::getline(stream, line))
		{
			if (line.find("#shader") != std::string::npos)
			{
				if (line.find("vertex") != std::string::npos)
				{
					type = ShaderType::VERTEX;
				}
				else if (line.find("fragment") != std::string::npos)
				{
					type = ShaderType::FRAGMENT;
				}
			}
			else
			{
				ss[static_cast<int>(type)] << line << '\n';
			}
		}

		return { ss[0].str(), ss[1].str() };
	}

	unsigned int ShaderCompiler::CompileShader(const unsigned int type, const std::string& source) const
	{
		const unsigned int id = glCreateShader(type);
		const char* src = source.c_str();
		glShaderSource(id, 1, &src, nullptr);
		glCompileShader(id);

		int status;
		glGetShaderiv(id, GL_COMPILE_STATUS, &status);
		if(status != GL_TRUE)
		{
			int size;
			char message[1024];
			glGetShaderInfoLog(id, 1024, &size, message);

			VEX_LOG_ERROR("[SHADER] [COMPILE ERROR] {}", message);

			return 0;
		}

		return id;
	}
}
