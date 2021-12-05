#pragma once

#include "Runtime.h"

class ModelViewer : public VEX::Game
{
protected:
	void Init() override;
	void Start() override;
	void Input(VEX::Window* window) override;
	void Update(float delta) override;
	void Render(VEX::Window* window) override;
	void Clean() override;
};

