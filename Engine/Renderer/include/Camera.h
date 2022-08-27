#pragma once

#include "Vex/Math.h"

namespace VEX
{
	enum class CameraProjection
	{
		ORTHOGRAPHIC,
		PERSPECTIVE
	};

    enum class CameraMovement
    {
        FORWARD,
        BACKWARD,
        LEFT,
        RIGHT
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

        glm::vec3 m_Position;
        float m_Yaw;
        float m_Pitch;

        glm::vec3 m_Front;
        glm::vec3 m_Right;
        glm::vec3 m_Up;
	public:
		Camera(const CameraConfig& config);
		~Camera();

		inline glm::mat4 GetMVP(const glm::mat4 model) const { return m_Projection * m_View * model; }

        void Move(const CameraMovement direction, float speed);
        void Look(float x, float y, bool constrain = true);
	private:
        void UpdateViewMatrix();
	};
}
