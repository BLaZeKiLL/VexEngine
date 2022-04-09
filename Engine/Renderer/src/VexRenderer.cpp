#include "Vex/Libs.h"
#include "Vex/Core.h"
#include "Vex/Resource.h"

#include "GLContext.h"

#include "VexRenderer.h"

namespace VEX
{
	VexRenderer::VexRenderer(const RendererConfig& config) :
	Config(config),
	GraphicsContext(new GLContext())
	{
	}

	VexRenderer::~VexRenderer()
	{
		delete GraphicsContext;
	}

	void VexRenderer::Init() const
	{
		VEX_LOG_INFO("Renderer Initialized");
	}

	void VexRenderer::Render() const
	{
		// Prepare
		glClear(GL_COLOR_BUFFER_BIT);
		glClearColor(Config.ClearColor.r, Config.ClearColor.g, Config.ClearColor.b, Config.ClearColor.a);
	}

	void VexRenderer::LoadMesh(Mesh& mesh) const
	{
		const auto vao = GraphicsContext->CreateVao();
		const auto vbo = GraphicsContext->CreateVbo();
		const auto ibo = GraphicsContext->CreateIbo();

		GraphicsContext->BindVao(vao);

		GraphicsContext->SetDataBuffer(vbo, 0, mesh.vertices.size() * sizeof(glm::vec3), &mesh.vertices[0]);
		GraphicsContext->SetIndexBuffer(ibo, mesh.indices.size() * sizeof(unsigned int), &mesh.indices[0]);

		mesh.id = vao;

		GraphicsContext->BindVao(0);
	}
}
