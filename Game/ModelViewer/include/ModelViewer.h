#pragma once

#include "Vex/Core.h"
#include "Vex/Runtime.h"

class ModelViewer final : public VEX::Game
{
protected:
	void Init() override;
	void Start() override;
	void Input(VEX::Window* window) override;
	void Update(float delta) override;
	void Render() override;
	void Clean() override;
};


