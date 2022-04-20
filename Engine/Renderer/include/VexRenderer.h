#pragma once

#include "Vex/Math.h"

namespace VEX
{
	class Mesh;
	class Shader;
	class Camera;

	struct CameraConfig;

	struct RendererConfig
	{
		glm::vec4 ClearColor;
		const CameraConfig& Camera;
	};

	class VexRenderer final
	{
	private:
		RendererConfig m_Config;

		Camera* m_Camera;
	public:
		VexRenderer(const RendererConfig& config);
		~VexRenderer();

		void PreRender() const;
		void Render(const Mesh* mesh, Shader* shader, const glm::mat4 transform) const;
		void PostRender() const;
	};
}
