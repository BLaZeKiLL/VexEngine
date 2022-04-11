#include "Vex/Core.h"
#include "Vex/Renderer.h"

#include "VexEngine.h"
#include "Game.h"

namespace VEX
{
	VexEngine::VexEngine(const VexEngineConfig& config) :
		m_Window(new VEX::Window(config.WindowConfig)),
		m_Timer(new VEX::Timer()),
		m_Renderer(new VexRenderer(config.RendererConfig)),
		m_Game(config.Game)
	{
		VEX_LOG_INFO("Vex Engine Constructed");
	}

	VexEngine::~VexEngine()
	{
		delete m_Renderer;
		delete m_Timer;
		delete m_Window;

		VEX_LOG_INFO("Vex Engine Destroyed");
	}

	void VexEngine::Bootstrap(const VexEngineConfig& config)
	{
		Logger::Init(config.WindowConfig.Title);

		const auto engine = new VexEngine(config);

		engine->Main();

		delete engine;
	}

	void VexEngine::Main() const
	{
		Start();
		Loop();
		Dispose();
	}

	void VexEngine::Start() const
	{
		m_Game->Start();
	}

	void VexEngine::Loop() const
	{
		float accumulator = 0.0f;
		constexpr float interval = 1.0f / TARGET_UPS;

		while (!m_Window->ShouldClose())
		{
			accumulator += m_Timer->GetElapsedTime();

			m_Game->Input(m_Window);

			while (accumulator >= interval)
			{
				m_Game->Update(interval);
				accumulator -= interval;
			}

			m_Renderer->Prepare();
			m_Game->Render(m_Renderer);
			m_Window->Update();
		}
	}

	void VexEngine::Dispose() const
	{
		m_Game->Dispose();
	}
}
