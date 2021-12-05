#include "VexEngine.h"

#include "Core.h"
#include "Game.h"

namespace VEX
{
	VexEngine::VexEngine(const VexEngineConfig& Config) :
		Game(Config.Game),
		Window(new VEX::Window(Config.WindowConfig)),
		Timer(new VEX::Timer())
	{
		Logger::Init(Config.WindowConfig.Title);
	}

	VexEngine::~VexEngine()
	{
		GameThread.join(); // Needs to be called

		VEX_LOG_INFO("Vex Engine Destroyed");
	}

	void VexEngine::Start()
	{
		GameThread = std::thread(&VexEngine::GameThreadRun, this);
	}

	void VexEngine::GameThreadRun() const
	{
		Init();
		Loop();
		Clean();
	}

	void VexEngine::Init() const
	{
		Window->Init();

		VEX_LOG_INFO("OpenGL 3.3 Initialized");

		Timer->Init();

		VEX_LOG_INFO("Vex Engine Initialized");

		Game->Init();

		VEX_LOG_INFO("Game Initialized");

		Game->Start();
	}

	void VexEngine::Loop() const
	{
		float accumulator = 0.0f;
		constexpr float interval = 1.0f / TARGET_UPS;

		while (!Window->ShouldClose())
		{
			accumulator += Timer->GetElapsedTime();

			Game->Input(Window);

			while (accumulator >= interval)
			{
				Game->Update(interval);
				accumulator -= interval;
			}

			Game->Render(Window);
			Window->Update();
		}
	}

	void VexEngine::Clean() const
	{
		Game->Clean();

		VEX_LOG_INFO("Game Clean Up");

		delete Window;

		VEX_LOG_INFO("Vex Engine Clean Up");
	}
}
