#include "Vex/Vex.h"

#include "Core/Core.h"

#include "ModelViewer.h"
#include "CameraController.h"


ModelViewer::ModelViewer() :
        m_Shader(nullptr),
        m_Texture(nullptr),
        m_Mesh(nullptr),
        m_CameraController(new CameraController(2.5f, 0.1f)),
        m_TransformData(new TransformData(glm::vec3(0.0f, 0.0f, -5.0f), glm::vec3(1.0f, 1.0f, 1.0f), 45.0f)),
        m_LightData(new LightData(glm::vec3(1.2f, 1.0f, -3.0f), glm::vec3(1.0f, 1.0f, 1.0f))),
        m_MaterialData(new MaterialData(glm::vec4(1.0f, 1.0f, 1.0f, 1.0f), 0.3f, 2.0f, 32))
{
}

ModelViewer::~ModelViewer()
{
}

void ModelViewer::Start()
{
	GAME_LOG_INFO("Game Start");

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
    UpdateShader();

	renderer->Render(
		m_Mesh,
		m_Shader,
		m_TransformData->GetTransform()
	);

    RenderUI();
}

void ModelViewer::Dispose()
{
    delete m_CameraController;

    delete m_TransformData;
    delete m_LightData;
    delete m_MaterialData;

    delete m_Mesh;
	delete m_Texture;
	delete m_Shader;

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

    m_Shader->SetUniform1i("u_Texture", 0);

    m_Shader->Unbind();
}

void ModelViewer::UpdateShader()
{
    m_Shader->Bind();

    // Light
    m_Shader->SetUniform3f("u_LightPosition", m_LightData->GetPosition());
    m_Shader->SetUniform3f("u_LightColor", m_LightData->GetColor());

    // Material
    m_Shader->SetUniform4f("u_BaseColor", m_MaterialData->GetBaseColor());
    m_Shader->SetUniform1f("u_AmbientStrength", m_MaterialData->GetAmbientStrength());
    m_Shader->SetUniform1f("u_SpecularStrength", m_MaterialData->GetSpecularStrength());
    m_Shader->SetUniform1i("u_SpecularShine", m_MaterialData->GetSpecularShine());

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

    ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);

    m_CameraController->RenderUI();
    m_TransformData->RenderUI();
    m_LightData->RenderUI();
    m_MaterialData->RenderUI();

    ImGui::End();
}
