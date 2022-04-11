#pragma once

#include <string>

namespace VEX
{
	class Shader;

	struct ShaderSource
	{
		std::string vertex;
		std::string fragment;
	};

	class ShaderCompiler final
	{
	private:
		enum class ShaderType
		{
			NONE = -1, VERTEX = 0, FRAGMENT = 1
		};
	public:
		Shader* Compile(const std::string& path) const;
	private:
		ShaderSource Preprocess(const std::string& path) const;

		unsigned int CompileShader(unsigned int type, const std::string& source) const;
	};
}
