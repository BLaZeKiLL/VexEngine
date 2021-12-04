#pragma once

#include "Core.h"

class Window;

namespace VEX
{
	class Game
	{
	public:
		virtual void Init() PURE;
		virtual void Start() PURE;
		virtual void Input(Window* window) PURE;
		virtual void Update(float delta) PURE;
		virtual void Render(Window* window) PURE;
		virtual void Clean() PURE;
	};
}
