#include "ModelViewer.h"

#include "Core.h"

void ModelViewer::Init()
{
}

void ModelViewer::Start()
{
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

void ModelViewer::Render(VEX::Window* window)
{
	glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
}

void ModelViewer::Clean()
{
}
