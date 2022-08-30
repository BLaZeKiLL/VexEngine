#include "Vex/Vendor.h"
#include "Vex/Resource.h"

#include "VexRenderer.h"
#include "Camera.h"

namespace VEX
{
	VexRenderer::VexRenderer(const RendererConfig& config) : m_Config(config), m_Camera(new Camera(config.Camera))
	{
	}

	VexRenderer::~VexRenderer()
	{
		delete m_Camera;
	}

	void VexRenderer::PreRender() const
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glClearColor(m_Config.ClearColor.r, m_Config.ClearColor.g, m_Config.ClearColor.b, m_Config.ClearColor.a);
	}

	void VexRenderer::Render(const Mesh* mesh, Shader* shader, const glm::mat4 transform) const
	{
		shader->Bind();
		mesh->Bind();

		shader->SetUniformMat4f("u_Model", transform);
		shader->SetUniformMat4f("u_ViewProjection", m_Camera->GetViewProjection());

        shader->SetUniform3f("u_ViewPosition", m_Camera->GetPosition());

		glDrawElements(GL_TRIANGLES, mesh->GetIndexCount(), GL_UNSIGNED_INT, nullptr);

		mesh->Unbind();
		shader->Unbind();
	}

	void VexRenderer::PostRender() const
	{

	}
}
