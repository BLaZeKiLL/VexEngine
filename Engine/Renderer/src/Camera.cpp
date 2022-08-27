#include "Vex/Core.h"

#include "Camera.h"

namespace VEX
{
	Camera::Camera(const CameraConfig& config):
            m_View(glm::mat4(1.0f)),
            m_Projection(glm::mat4(1.0f)),
            m_Position(glm::vec3(0.0f, 0.0f, 0.0f)),
            m_Pitch(0.0f),
            m_Yaw(-90.0f),
            m_XLast(config.Width / 2),
            m_YLast(config.Height / 2),
            m_FirstMouse(true)
	{
		switch (config.Projection)
		{
		case CameraProjection::ORTHOGRAPHIC:
			m_Projection = glm::ortho(0.0f, config.Width, 0.0f, config.Height, 0.1f, 1000.0f);
			break;
		case CameraProjection::PERSPECTIVE:
			m_Projection = glm::perspective(glm::radians(45.0f), config.Width / config.Height, 0.1f, 1000.0f);
			break;
		default: ;
		}

        UpdateViewMatrix();
	}

	Camera::~Camera()
	{
	}

    void Camera::Move(const CameraMovement direction, float speed) {
        if (direction == CameraMovement::FORWARD)
            m_Position += m_Front * speed;
        if (direction == CameraMovement::BACKWARD)
            m_Position -= m_Front * speed;
        if (direction == CameraMovement::LEFT)
            m_Position -= m_Right * speed;
        if (direction == CameraMovement::RIGHT)
            m_Position += m_Right * speed;

        UpdateViewMatrix();
    }

    void Camera::Look(float x, float y, float sensitivity, bool constrain) {
        if (m_FirstMouse) {
            m_XLast = x;
            m_YLast = y;

            m_FirstMouse = false;
        }

        auto x_offset = x - m_XLast;
        auto y_offset = m_YLast - y;

        m_XLast = x;
        m_YLast = y;

        x_offset *= sensitivity;
        y_offset *= sensitivity;

        m_Yaw += x_offset;
        m_Pitch += y_offset;

        if (constrain) {
            if (m_Pitch > 89.0f) m_Pitch = 89.0f;
            if (m_Pitch < -89.0f) m_Pitch = -89.0f;
        }

        UpdateViewMatrix();
    }

    void Camera::UpdateViewMatrix() {
        glm::vec3 front;

        front.x = cos(glm::radians(m_Yaw)) * cos(glm::radians(m_Pitch));
        front.y = sin(glm::radians(m_Pitch));
        front.z = sin(glm::radians(m_Yaw)) * cos(glm::radians(m_Pitch));

        m_Front = glm::normalize(front);

        m_Right = glm::normalize(glm::cross(m_Front, glm::vec3(0.0f, 1.0f, 0.0f)));
        m_Up = glm::normalize(glm::cross(m_Right, m_Front));

        m_View = glm::lookAt(m_Position, m_Position + m_Front, m_Up);

        VEX_LOG_TRACE("Camera View : {}", glm::to_string(m_View));
    }

    void Camera::LookReset() {
        m_FirstMouse = true;
    }

}
