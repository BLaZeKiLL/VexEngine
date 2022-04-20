
#include "Camera.h"

namespace VEX
{
	Camera::Camera(const CameraConfig& config):
		m_Projection(glm::mat4(1.0f)),
		m_View(glm::mat4(1.0f))
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

		m_View = glm::translate(m_View, glm::vec3(0.0f, 0.0f, -5.0f));
	}

	Camera::~Camera()
	{
	}
}
