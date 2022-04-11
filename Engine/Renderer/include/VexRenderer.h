#pragma once

#include "Vex/Libs.h"

namespace VEX
{
	class Mesh;
	class Shader;

	struct RendererConfig
	{
		glm::vec4 ClearColor;
	};

	class VexRenderer final
	{
	private:
		RendererConfig m_Config;

	public:
		VexRenderer(const RendererConfig& config);
		~VexRenderer();

		void Prepare() const;
		void Render(const Mesh* mesh, const Shader* shader) const;
	};
}
