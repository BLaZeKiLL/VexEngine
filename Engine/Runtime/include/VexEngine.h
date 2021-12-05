#pragma once

#include <thread>

namespace VEX
{
	class Timer;
	class Window;
	class Game;

	struct WindowConfig;

	struct VexEngineConfig
	{
		const WindowConfig& WindowConfig;
		Game* Game;
	};

	class VexEngine
	{
	public:
		VexEngine(const VexEngineConfig& Config);
		~VexEngine();

		static constexpr int TARGET_FPS = 120;
		static constexpr int TARGET_UPS = 60;

		void Start();

	private:
		Game* Game;

		Window* Window;
		Timer* Timer;

		std::thread GameThread;

		void GameThreadRun() const;

		void Init() const;
		void Loop() const;
		void Clean() const;
	};
}
