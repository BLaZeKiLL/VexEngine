#include "Timer.h"

#include <chrono>

namespace VEX
{
	void Timer::Init()
	{
		_LastLoopTime = GetTime();
	}

	double Timer::GetTime()
	{
		auto time = std::chrono::time_point_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now()).time_since_epoch().count();
		return time / 1000000000.0;
	}

	float Timer::GetElapsedTime()
	{
		auto time = GetTime();
		auto elapsedTime = (float)(time - _LastLoopTime);
		_LastLoopTime = time;
		return elapsedTime;
	}
}
