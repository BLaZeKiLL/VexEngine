#include <spdlog/sinks/stdout_color_sinks.h>

#include "Logger.h"

namespace VEX
{
	std::shared_ptr<spdlog::logger> Logger::s_Logger;

	void Logger::Init()
	{
		spdlog::set_pattern("%^[%n][%T][%4!l]%$ : %v");
		s_Logger = spdlog::stdout_color_mt("VEX");
		s_Logger->set_level(spdlog::level::trace);
	}
}
