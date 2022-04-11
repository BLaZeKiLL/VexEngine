#include "ModelViewer.h"

#include "Vex/Libs.h"
#include "Vex/Core.h"

void ModelViewer::Start() // Game State Initialization
{
	GAME_LOG_INFO("Game Start");
}

void ModelViewer::Input(VEX::Window* window)
{
	if (window->IsKeyPressed(GLFW_KEY_ESCAPE)) {
		window->Close();
	}
}

void ModelViewer::Update(float delta)
{
	//GAME_LOG_INFO("UPDATE: {}", delta);
}

void ModelViewer::Render()
{

}

void ModelViewer::Dispose()
{
	GAME_LOG_INFO("Game Dispose");
}
