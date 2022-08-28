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

        float m_XLast;
        float m_YLast;

        bool m_FirstMouse;

	public:
		Camera(const CameraConfig& config);
		~Camera();

        inline const glm::vec3& GetPosition() const { return m_Position; }
		inline const glm::mat4& GetView() const { return m_View; }
		inline const glm::mat4& GetProjection() const { return m_Projection; }

        void Move(CameraMovement direction, float speed);
        void Look(float x, float y, float sensitivity, bool constrain = true);

        void LookReset();

    private:
        void UpdateViewMatrix();
    };
}
