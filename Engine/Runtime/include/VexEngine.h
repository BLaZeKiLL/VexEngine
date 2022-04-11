#pragma once

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
	private:
		Window* m_Window;
		Timer* m_Timer;
		VexRenderer* m_Renderer;

		Game* m_Game;
	public:
		VexEngine(const VexEngineConfig& config);
		~VexEngine();

		static constexpr int TARGET_FPS = 120;
		static constexpr int TARGET_UPS = 60;

		static void Bootstrap(const VexEngineConfig& config);
	private:
		void Main() const;
		void Start() const;
		void Loop() const;
		void Dispose() const;
	};
}
