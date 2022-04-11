#pragma once

#include "Vex/Runtime.h"

namespace VEX
{
	class Mesh;
	class Shader;
	class Window;
	class VexRenderer;
}

class ModelViewer final : public VEX::Game
{
private:
	VEX::Shader* m_Shader;
	VEX::Mesh* m_Mesh;
protected:
	void Start() override;
	void Input(const VEX::Window* window) override;
	void Update(float delta) override;
	void Render(const VEX::VexRenderer* renderer) override;
	void Dispose() override;
};


