#include "Vex/Libs.h"
#include "Vex/Core.h"
#include "Vex/Platform.h"

#include "VexRenderer.h"

namespace VEX
{
	VexRenderer::VexRenderer(const RendererConfig& config) : m_Config(config)
	{
	}

	VexRenderer::~VexRenderer()
	{
		delete m_VB;
		delete m_IB;
		delete m_VA;
	}

	void VexRenderer::Init()
	{
		const glm::vec2 positions[] = {
			glm::vec2(-0.5f, -0.5f),
			glm::vec2(-0.5f, 0.5f),
			glm::vec2(0.5f, -0.5f),
			glm::vec2(0.5f, 0.5f),
		};

		const unsigned int indices[] = {
			0, 1, 2,
			2, 1, 3
		};

		m_VA = new VertexArray();

		m_VB = new VertexBuffer(positions, 4 * sizeof(glm::vec2));

		VertexBufferLayout layout;

		layout.Push<float>(2);

		m_VA->AddBuffer(m_VB, layout);

		m_IB = new IndexBuffer(indices, 6);

		VEX_LOG_INFO("Renderer Initialized");
	}

	void VexRenderer::Render() const
	{
		// Prepare
		glClear(GL_COLOR_BUFFER_BIT);
		glClearColor(m_Config.ClearColor.r, m_Config.ClearColor.g, m_Config.ClearColor.b, m_Config.ClearColor.a);

		// Render
		m_VA->Bind();
		m_IB->Bind();

		glDrawElements(GL_TRIANGLES, m_IB->GetCount(), GL_UNSIGNED_INT, nullptr);

		m_IB->Unbind();
		m_VA->Unbind();
	}
}
