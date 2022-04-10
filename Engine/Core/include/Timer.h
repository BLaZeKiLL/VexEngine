#pragma once

namespace VEX
{
	class Timer
	{
	private:
		double m_LastLoopTime;
	public:
		void Init();
		double GetTime() const;
		float GetElapsedTime();
	};
}
