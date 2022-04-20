#pragma once

#include "Vex/Math.h"

namespace VEX
{
	enum class CameraProjection
	{
		ORTHOGRAPHIC,
		PERSPECTIVE
	};

	struct CameraConfig
	{
		const CameraProjection Projection;
		const float Width;
		const float Height;
	};

	class Camera final
	{
	private:
		glm::mat4 m_Projection;
		glm::mat4 m_View;
	public:
		Camera(const CameraConfig& config);
		~Camera();

		inline glm::mat4 GetMVP(const glm::mat4 model) const { return m_Projection * m_View * model; }
	private:

	};
}
