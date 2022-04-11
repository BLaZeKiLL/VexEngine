#include "Timer.h"

#include <chrono>

namespace VEX
{
	Timer::Timer() : m_LastLoopTime(GetTime())
	{
	}

	double Timer::GetTime() const
	{
		const auto time = std::chrono::time_point_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now()).time_since_epoch().count();
		return time / 1000000000.0;
	}

	float Timer::GetElapsedTime()
	{
		const auto time = GetTime();
		const auto elapsedTime = (float)(time - m_LastLoopTime);
		m_LastLoopTime = time;
		return elapsedTime;
	}
}
