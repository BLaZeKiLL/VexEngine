#include "Vex/Libs.h"
#include "Vex/Resource.h"
#include "Vex/Platform/OpenGL.h"

#include "VexRenderer.h"

namespace VEX
{
	VexRenderer::VexRenderer(const RendererConfig& config) : m_Config(config)
	{
	}

	VexRenderer::~VexRenderer()
	{
	}

	void VexRenderer::Prepare() const
	{
		glClear(GL_COLOR_BUFFER_BIT);
		glClearColor(m_Config.ClearColor.r, m_Config.ClearColor.g, m_Config.ClearColor.b, m_Config.ClearColor.a);
	}

	void VexRenderer::Render(const Mesh* mesh, const Shader* shader) const
	{
		shader->Bind();
		mesh->Bind();

		glDrawElements(GL_TRIANGLES, mesh->GetIndexCount(), GL_UNSIGNED_INT, nullptr);

		mesh->Unbind();
		shader->Unbind();
	}
}
