#include "Vex/Vex.h"

#include "CameraController.h"

CameraController::CameraController(float speed, float sensitivity) : m_Speed(speed), m_Sensitivity(sensitivity)
{}

void CameraController::ProcessInput(const VEX::Window *window, VEX::Camera *camera) const
{
    // Camera - Keyboard
    float speed = m_Speed * window->GetDeltaTime();

    if (window->GetKeyAction(GLFW_KEY_W) == GLFW_PRESS)
        camera->Move(VEX::CameraMovement::FORWARD, speed);
    if (window->GetKeyAction(GLFW_KEY_S) == GLFW_PRESS)
        camera->Move(VEX::CameraMovement::BACKWARD, speed);
    if (window->GetKeyAction(GLFW_KEY_A) == GLFW_PRESS)
        camera->Move(VEX::CameraMovement::LEFT, speed);
    if (window->GetKeyAction(GLFW_KEY_D) == GLFW_PRESS)
        camera->Move(VEX::CameraMovement::RIGHT, speed);

    // Camera - Mouse
    if (window->GetMouseAction(GLFW_MOUSE_BUTTON_RIGHT) == GLFW_PRESS)
        window->LockCursor(true);
    if (window->GetMouseAction(GLFW_MOUSE_BUTTON_RIGHT) == GLFW_RELEASE)
        window->LockCursor(false);

    if (window->IsCursorLocked()) {
        double x_pos, y_pos;

        window->GetCursorPosition(&x_pos, &y_pos);

        camera->Look(x_pos, y_pos, m_Sensitivity);
    } else {
        camera->LookReset();
    }
}

void CameraController::RenderUI()
{
    if (ImGui::CollapsingHeader("Camera")) {
        ImGui::SliderFloat("Speed", &m_Speed, 1.0f, 10.0f);
        ImGui::SliderFloat("Sensitivity", &m_Sensitivity, 0.01f, 1.0f);
    }
}
