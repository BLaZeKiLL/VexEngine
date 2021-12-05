#include <spdlog/sinks/stdout_color_sinks.h>

#include "Logger.h"

namespace VEX
{
	std::shared_ptr<spdlog::logger> Logger::EngineLogger;
	std::shared_ptr<spdlog::logger> Logger::GameLogger;

	void Logger::Init(const std::string& name)
	{
		spdlog::set_pattern("%^[%n][%T][%4!l]%$ : %v");

		EngineLogger = spdlog::stdout_color_mt("VEX");
		EngineLogger->set_level(spdlog::level::trace);

		GameLogger = spdlog::stdout_color_mt(name);
		GameLogger->set_level(spdlog::level::trace);
	}
}
