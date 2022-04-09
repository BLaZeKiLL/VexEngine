#pragma once

#include "Vex/Libs.h"

namespace VEX
{
	class GLContext;
	class Mesh;

	struct RendererConfig
	{
		glm::vec4 ClearColor;
	};

	class VexRenderer final
	{
	private:
		RendererConfig Config;
		GLContext* GraphicsContext;

	public:
		VexRenderer(const RendererConfig& config);
		~VexRenderer();

		void Init() const;
		void Render() const;
		void LoadMesh(Mesh& mesh) const;
	};
}
