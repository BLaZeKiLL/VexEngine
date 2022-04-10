#pragma once

#include "Vex/Libs.h"

namespace VEX
{
	class VertexBuffer;
	class IndexBuffer;
	class VertexArray;

	struct RendererConfig
	{
		glm::vec4 ClearColor;
	};

	class VexRenderer final
	{
	private:
		RendererConfig m_Config;

		VertexBuffer* m_VB;
		IndexBuffer* m_IB;
		VertexArray* m_VA;

	public:
		VexRenderer(const RendererConfig& config);
		~VexRenderer();

		void Init();
		void Render() const;
	};
}
