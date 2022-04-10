#include <spdlog/sinks/stdout_color_sinks.h>

#include "Logger.h"

namespace VEX
{
	std::shared_ptr<spdlog::logger> Logger::m_EngineLogger;
	std::shared_ptr<spdlog::logger> Logger::m_GameLogger;

	void Logger::Init(const std::string& name)
	{
		spdlog::set_pattern("%^[%n][%T][%4!l]%$ : %v");

		m_EngineLogger = spdlog::stdout_color_mt("VEX");
		m_EngineLogger->set_level(spdlog::level::trace);

		m_GameLogger = spdlog::stdout_color_mt(name);
		m_GameLogger->set_level(spdlog::level::trace);
	}
}
