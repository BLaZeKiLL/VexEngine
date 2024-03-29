#pragma once

#include "Vex/Minimal.h"

namespace VEX
{
	class Window;
    class Camera;
	class VexRenderer;

	class Game
	{
	public:
		virtual void Start() PURE;
		virtual void Input(const Window* window, Camera* camera) PURE;
		virtual void Update(float delta) PURE;
		virtual void Render(const VexRenderer* renderer) PURE;
		virtual void Dispose() PURE;
	};
}
