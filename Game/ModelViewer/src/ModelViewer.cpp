#include "Vex/Vex.h"

#include "ModelViewer.h"
#include "CameraController.h"
#include "Primitives.h"
#include "Vertex.h"

ModelViewer::ModelViewer() :
        m_Shader(nullptr),
        m_Texture(nullptr),
        m_Mesh(nullptr),
        m_Transform(glm::mat4(1.0f)),
        m_Position(glm::vec3(0.0f, 0.0f, -5.0f)),
        m_Axis(glm::vec3(1.0f, 1.0f, 1.0f)),
        m_Rotation(45.0f)
{
}

ModelViewer::~ModelViewer()
{
}

void ModelViewer::Start()
{
	GAME_LOG_INFO("Game Start");

    m_CameraController = new CameraController(2.5f, 0.1f);

    SetupShader();
    SetupModel();
}

void ModelViewer::Input(const VEX::Window* window, VEX::Camera* camera)
{
	if (window->GetKeyAction(GLFW_KEY_ESCAPE) == GLFW_PRESS) {
		window->Close();
	}

    m_CameraController->ProcessInput(window, camera);
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
			glm::translate(m_Transform, m_Position),
			glm::radians(m_Rotation),
			glm::normalize(m_Axis)
		)
	);

    RenderUI();
}

void ModelViewer::Dispose()
{
	delete m_Mesh;
	delete m_Texture;
	delete m_Shader;

    delete m_CameraController;

	GAME_LOG_INFO("Game Dispose");
}

void ModelViewer::SetupShader()
{
    const auto* compiler = new VEX::ShaderCompiler();

    m_Shader = compiler->Compile("assets/Shaders/default.shader");

    delete compiler;

    m_Texture = new VEX::Texture("assets/Textures/codeblaze.png");

    m_Texture->Bind();
    m_Shader->Bind();

    m_Shader->SetUniform1i("u_Texture", glm::ivec1(0));
    m_Shader->SetUniform4f("u_LightColor", glm::vec4(1.0f, 1.0f, 1.0f, 1.0f));
    m_Shader->SetUniform4f("u_ObjectColor", glm::vec4(1.0f, 0.5f, 0.31f, 1.0f));

    m_Shader->Unbind();
}

void ModelViewer::SetupModel()
{
    auto data = Primitives::Cube();

    m_Mesh = new VEX::Mesh(data->layout, data->vertices, data->vertex_count, data->indices, data->index_count);

    delete data;
}

void ModelViewer::RenderUI()
{
    ImGui::Begin("Model Viewer");

    ImGui::Text("Welcome to Model Viewer");
    ImGui::InputFloat3("Position", glm::value_ptr(m_Position));
    ImGui::SliderFloat3("Axis", glm::value_ptr(m_Axis), 0.0f, 1.0f);
    ImGui::SliderFloat("Rotation", &m_Rotation, 0.0f, 360.0f);
    ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);

    ImGui::End();
}
