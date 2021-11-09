#pragma once

#include <memory>
#include <spdlog/spdlog.h>

namespace VEX
{
	class Logger
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetLogger();

	private:
		static std::shared_ptr<spdlog::logger> s_Logger;
	};

	std::shared_ptr<spdlog::logger>& Logger::GetLogger()
	{
		return s_Logger;
	}
}

#define VEX_LOG_ERROR(...) VEX::Logger::GetLogger()->error(__VA_ARGS__)
#define VEX_LOG_WARN(...) VEX::Logger::GetLogger()->warn(__VA_ARGS__)
#define VEX_LOG_INFO(...) VEX::Logger::GetLogger()->info(__VA_ARGS__)
#define VEX_LOG_DEBUG(...) VEX::Logger::GetLogger()->debug(__VA_ARGS__)
#define VEX_LOG_TRACE(...) VEX::Logger::GetLogger()->trace(__VA_ARGS__)
