#pragma once

#include <memory>
#include <spdlog/spdlog.h>

namespace VEX
{
	class Logger
	{
	private:
		static std::shared_ptr<spdlog::logger> m_EngineLogger;
		static std::shared_ptr<spdlog::logger> m_GameLogger;

	public:
		static void Init(const std::string& name);

		inline static std::shared_ptr<spdlog::logger>& GetEngineLogger();
		inline static std::shared_ptr<spdlog::logger>& GetGameLogger();
	};

	std::shared_ptr<spdlog::logger>& Logger::GetEngineLogger()
	{
		return m_EngineLogger;
	}

	std::shared_ptr<spdlog::logger>& Logger::GetGameLogger()
	{
		return m_GameLogger;
	}
}

#define VEX_LOG_ERROR(...) VEX::Logger::GetEngineLogger()->error(__VA_ARGS__)
#define VEX_LOG_WARN(...) VEX::Logger::GetEngineLogger()->warn(__VA_ARGS__)
#define VEX_LOG_INFO(...) VEX::Logger::GetEngineLogger()->info(__VA_ARGS__)
#define VEX_LOG_DEBUG(...) VEX::Logger::GetEngineLogger()->debug(__VA_ARGS__)
#define VEX_LOG_TRACE(...) VEX::Logger::GetEngineLogger()->trace(__VA_ARGS__)

#define GAME_LOG_ERROR(...) VEX::Logger::GetGameLogger()->error(__VA_ARGS__)
#define GAME_LOG_WARN(...) VEX::Logger::GetGameLogger()->warn(__VA_ARGS__)
#define GAME_LOG_INFO(...) VEX::Logger::GetGameLogger()->info(__VA_ARGS__)
#define GAME_LOG_DEBUG(...) VEX::Logger::GetGameLogger()->debug(__VA_ARGS__)
#define GAME_LOG_TRACE(...) VEX::Logger::GetGameLogger()->trace(__VA_ARGS__)
