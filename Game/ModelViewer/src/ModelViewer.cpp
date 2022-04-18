#include "Vex/Vex.h"

#include "ModelViewer.h"

#include "glm/gtc/matrix_transform.hpp"


ModelViewer::ModelViewer() : m_Shader(nullptr), m_Texture(nullptr), m_Mesh(nullptr)
{
}

ModelViewer::~ModelViewer()
{
}

void ModelViewer::Start()
{
	GAME_LOG_INFO("Game Start");

	const auto* compiler = new VEX::ShaderCompiler();

	m_Shader = compiler->Compile("assets/Shaders/default.shader");

	delete compiler;

	m_Texture = new VEX::Texture("assets/Textures/codeblaze_trans.png");

	m_Texture->Bind();
	m_Shader->Bind();

	// 16:9 Orthographic Projection
	const glm::mat4 proj = glm::ortho(0.0f, 1280.0f, 0.0f, 720.0f, -1.0f, 1.0f);
	const glm::mat4 view = glm::translate(glm::mat4(1.0f), glm::vec3(-100, 0, 0));
	const glm::mat4 model = glm::translate(glm::mat4(1.0f), glm::vec3(200, 200, 0));

	const glm::mat4 mvp = proj * view * model;

	m_Shader->SetUniformMat4f("u_MVP", mvp);
	m_Shader->SetUniform1i("u_Texture", glm::ivec1(0));

	m_Shader->Unbind();

	constexpr glm::vec2 vertices[] = {
		glm::vec2(100.0f, 100.0f), glm::vec2(0.0f, 0.0f),
		glm::vec2(100.0f, 200.0f), glm::vec2(0.0f, 1.0f),
		glm::vec2(200.0f, 100.0f), glm::vec2(1.0f, 0.0f),
		glm::vec2(200.0f, 200.0f), glm::vec2(1.0f, 1.0f),
	};

	constexpr unsigned int indices[] = {
		0, 1, 2,
		2, 1, 3
	};

	VEX::VertexBufferLayout layout;

	layout.Push<float>(2); // Positions
	layout.Push<float>(2); // UV's

	m_Mesh = new VEX::Mesh(layout, vertices, 4, indices, 6);
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

	bool show_demo_window = true;
	ImGui::ShowDemoWindow(&show_demo_window);
}

void ModelViewer::Dispose()
{
	delete m_Mesh;
	delete m_Texture;
	delete m_Shader;

	GAME_LOG_INFO("Game Dispose");
}
