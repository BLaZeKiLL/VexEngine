#pragma once

struct WindowConfig;

class Timer;
class Window;
class Game;

namespace VEX
{
	struct VexEngineConfig
	{
		const WindowConfig& WindowConfig;
		const Game* Game;
	};

	class VexEngine
	{
	public:
		VexEngine();

		static constexpr int TARGET_FPS = 120;
		static constexpr int TARGET_UPS = 60;
	private:
		const Timer* Timer;
		const Window* Window;
		const Game* Game;
	};
}
