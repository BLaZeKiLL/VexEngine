#pragma once

namespace VEX
{
	class Timer
	{
	public:
		void Init();
		double GetTime();
		float GetElapsedTime();

	private:
		double _LastLoopTime;
	};
}
