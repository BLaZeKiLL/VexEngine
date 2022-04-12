#include "Vex/Vex.h"

#include "ModelViewer.h"


void ModelViewer::Start()
{
	GAME_LOG_INFO("Game Start");

	const auto* compiler = new VEX::ShaderCompiler();

	m_Shader = compiler->Compile("assets/Shaders/default.shader");

	delete compiler;

	m_Shader->Bind();
	m_Shader->SetUniform4f("u_Color", glm::vec4(0.5f, 4.0f, 0.8f, 1.0f));
	m_Shader->Unbind();

	constexpr glm::vec2 vertices[] = {
		glm::vec2(-0.5f, -0.5f),
		glm::vec2(-0.5f, 0.5f),
		glm::vec2(0.5f, -0.5f),
		glm::vec2(0.5f, 0.5f),
	};

	constexpr unsigned int indices[] = {
		0, 1, 2,
		2, 1, 3
	};

	VEX::VertexBufferLayout layout;

	layout.Push<float>(2);

	m_Mesh = new VEX::Mesh(layout, vertices, 4 * sizeof(glm::vec2), indices, 6);
}

void ModelViewer::Input(const VEX::Window* window)
{
	if (window->IsKeyPressed(GLFW_KEY_ESCAPE)) {
		window->Close();
	}
}

void ModelViewer::Update(float delta)
{

}

void ModelViewer::Render(const VEX::VexRenderer* renderer)
{
	renderer->Render(m_Mesh, m_Shader);
}

void ModelViewer::Dispose()
{
	delete m_Mesh;
	delete m_Shader;

	GAME_LOG_INFO("Game Dispose");
}
