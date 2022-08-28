#pragma once

namespace VEX
{
    class Camera;
    class Window;
}

class CameraController final
{
private:
    float m_Speed;
    float m_Sensitivity;
public:
    CameraController(float speed, float sensitivity);

    void ProcessInput(const VEX::Window* window, VEX::Camera* camera) const;
    void RenderUI();
};