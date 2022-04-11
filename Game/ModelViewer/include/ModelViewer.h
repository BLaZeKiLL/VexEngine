#pragma once

#include "Vex/Core.h"
#include "Vex/Runtime.h"

namespace VEX
{
	class Shader;
}

class ModelViewer final : public VEX::Game
{
private:
	VEX::Shader* m_shader;
protected:
	void Start() override;
	void Input(VEX::Window* window) override;
	void Update(float delta) override;
	void Render() override;
	void Dispose() override;
};


