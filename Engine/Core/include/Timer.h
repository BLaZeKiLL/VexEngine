#pragma once

namespace VEX
{
	class Timer
	{
	private:
		double m_LastLoopTime;
	public:
		Timer();

		double GetTime() const;
		float GetElapsedTime();
	};
}
