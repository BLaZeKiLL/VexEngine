#include "Vex/Vex.h"

#include "ModelViewer.h"

#include "glm/gtc/matrix_transform.hpp"


VEX::VertexBufferLayout Vertex::GetLayout()
{
	VEX::VertexBufferLayout layout;

	layout.Push<float>(3); // Positions
	layout.Push<float>(2); // UV's

	return layout;
}

ModelViewer::ModelViewer() :
	m_Shader(nullptr),
	m_Texture(nullptr),
	m_Mesh(nullptr),
	m_Model(glm::mat4(1.0f)),
	m_Position(glm::vec3(0.0f, 0.0f, 0.0f))
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

	m_Texture = new VEX::Texture("assets/Textures/codeblaze.png");

	m_Texture->Bind();
	m_Shader->Bind();

	m_Shader->SetUniform1i("u_Texture", glm::ivec1(0));

	m_Shader->Unbind();

	// ORTHOGRAPHIC SQUARE
	// constexpr glm::vec2 vertices[] = {
	// 	glm::vec2(-100.0f, -100.0f), glm::vec2(0.0f, 0.0f),
	// 	glm::vec2(-100.0f,  100.0f), glm::vec2(0.0f, 1.0f),
	// 	glm::vec2( 100.0f, -100.0f), glm::vec2(1.0f, 0.0f),
	// 	glm::vec2( 100.0f,  100.0f), glm::vec2(1.0f, 1.0f),
	// };

	// PERSPECTIVE SQUARE
	constexpr Vertex vertices[] = {
		Vertex { glm::vec3(-0.5f, -0.5f, 0.0f), glm::vec2(0.0f, 0.0f) },
		Vertex { glm::vec3(-0.5f,  0.5f, 0.0f), glm::vec2(0.0f, 1.0f) },
		Vertex { glm::vec3( 0.5f, -0.5f, 0.0f), glm::vec2(1.0f, 0.0f) },
		Vertex { glm::vec3( 0.5f,  0.5f, 0.0f), glm::vec2(1.0f, 1.0f) },
	};

	constexpr unsigned int indices[] = {
		0, 1, 2,
		2, 1, 3
	};

	auto layout = Vertex::GetLayout();

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
	renderer->Render(
		m_Mesh,
		m_Shader,
		glm::rotate(
			glm::translate(m_Model, m_Position),
			glm::radians(-45.0f),
			glm::vec3(1.0f, 0.0f, 0.0f)
		)
	);

	ImGui::Begin("Model Viewer");

	ImGui::Text("Welcome to Model Viewer");
	ImGui::SliderFloat3("Position", glm::value_ptr(m_Position), -4.0f, 4.0f);
	ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);

	ImGui::End();
}

void ModelViewer::Dispose()
{
	delete m_Mesh;
	delete m_Texture;
	delete m_Shader;

	GAME_LOG_INFO("Game Dispose");
}
