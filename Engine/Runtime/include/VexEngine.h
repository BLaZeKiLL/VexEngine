#pragma once

#include <thread>

namespace VEX
{
	class Timer;
	class Window;
	class Game;
	class VexRenderer;

	struct WindowConfig;
	struct RendererConfig;

	struct VexEngineConfig
	{
		const WindowConfig& WindowConfig;
		const RendererConfig& RendererConfig;
		Game* Game;
	};

	class VexEngine final
	{
	public:
		VexEngine(const VexEngineConfig& Config);
		~VexEngine();

		static constexpr int TARGET_FPS = 120;
		static constexpr int TARGET_UPS = 60;

		void Start();

	private:
		Game* Game;
		VexRenderer* Renderer;
		Window* Window;
		Timer* Timer;

		std::thread GameThread;

		void GameThreadRun() const;

		void Init() const;
		void Loop() const;
		void Clean() const;
	};
}
