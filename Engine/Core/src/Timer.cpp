#include "Timer.h"

#include <chrono>

namespace VEX
{
	void Timer::Init()
	{
		m_LastLoopTime = GetTime();
	}

	double Timer::GetTime() const
	{
		auto time = std::chrono::time_point_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now()).time_since_epoch().count();
		return time / 1000000000.0;
	}

	float Timer::GetElapsedTime()
	{
		auto time = GetTime();
		auto elapsedTime = (float)(time - m_LastLoopTime);
		m_LastLoopTime = time;
		return elapsedTime;
	}
}
