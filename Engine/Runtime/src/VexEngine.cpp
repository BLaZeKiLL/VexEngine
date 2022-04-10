#include "Vex/Core.h"
#include "Vex/Renderer.h"

#include "VexEngine.h"
#include "Game.h"

namespace VEX
{
	VexEngine::VexEngine(const VexEngineConfig& Config) :
		m_Game(Config.Game),
		m_Renderer(new VexRenderer(Config.RendererConfig)),
		m_Window(new VEX::Window(Config.WindowConfig)),
		m_Timer(new VEX::Timer())
	{
		Logger::Init(Config.WindowConfig.Title);
	}

	VexEngine::~VexEngine()
	{
		m_GameThread.join(); // Needs to be called

		VEX_LOG_INFO("Vex Engine Destroyed");
	}

	void VexEngine::Start()
	{
		m_GameThread = std::thread(&VexEngine::GameThreadRun, this);
	}

	void VexEngine::GameThreadRun() const
	{
		Init();
		Loop();
		Clean();
	}

	void VexEngine::Init() const
	{
		m_Window->Init();
		m_Timer->Init();
		m_Renderer->Init();

		VEX_LOG_INFO("Vex Engine Initialized");

		m_Game->Init();

		VEX_LOG_INFO("Game Initialized");

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

			m_Renderer->Render();
			m_Window->Update();
		}
	}

	void VexEngine::Clean() const
	{
		m_Game->Clean();

		VEX_LOG_INFO("Game Clean Up");

		delete m_Window;
		delete m_Renderer;
		delete m_Timer;

		VEX_LOG_INFO("Vex Engine Clean Up");
	}
}
