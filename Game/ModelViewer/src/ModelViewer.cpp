#include "ModelViewer.h"

#include "Platform/OpenGL/Shader.h"
#include "Vex/Libs.h"
#include "Vex/Core.h"
#include "Vex/Shader.h"

void ModelViewer::Start() // Game State Initialization
{
	GAME_LOG_INFO("Game Start");

	const auto* compiler = new VEX::ShaderCompiler();

	m_shader = compiler->Compile("assets/Shaders/default.shader");

	m_shader->Bind();
	m_shader->SetUniform4fv("u_Color", glm::vec4(0.1f, 1.0f, 0.1f, 1.0f));

	delete compiler;
}

void ModelViewer::Input(VEX::Window* window)
{
	if (window->IsKeyPressed(GLFW_KEY_ESCAPE)) {
		window->Close();
	}
}

void ModelViewer::Update(float delta)
{

}

void ModelViewer::Render()
{

}

void ModelViewer::Dispose()
{
	delete m_shader;

	GAME_LOG_INFO("Game Dispose");
}
