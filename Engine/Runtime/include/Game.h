#pragma once

#include "Vex/Minimal.h"

namespace VEX
{
	class Window;

	class Game
	{
	public:
		virtual ~Game() = default;

		virtual void Start() PURE;
		virtual void Input(Window* window) PURE;
		virtual void Update(float delta) PURE;
		virtual void Render() PURE;
		virtual void Dispose() PURE;
	};
}
