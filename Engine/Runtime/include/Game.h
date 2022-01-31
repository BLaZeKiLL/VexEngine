#pragma once

#include "Vex/Core.h"

namespace VEX
{
	class Window;

	class Game
	{
	public:
		virtual ~Game() = default;

		virtual void Init() PURE;
		virtual void Start() PURE;
		virtual void Input(Window* window) PURE;
		virtual void Update(float delta) PURE;
		virtual void Render(Window* window) PURE;
		virtual void Clean() PURE;
	};
}
