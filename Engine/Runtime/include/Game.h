#pragma once

class Window;

namespace VEX
{
	class Game
	{
	public:
		virtual void Init() = 0;
		virtual void Start() = 0;
		virtual void Input(Window* window) = 0;
		virtual void Update(float delta) = 0;
		virtual void Render(Window* window) = 0;
		virtual void Clean() = 0;
	};
}
