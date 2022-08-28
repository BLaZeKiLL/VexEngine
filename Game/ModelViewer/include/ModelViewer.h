#pragma once

#include "Vex/Math.h"
#include "Vex/Runtime.h"

namespace VEX
{
	class Mesh;
    class Camera;
	class Shader;
	class Window;
	class Texture;
	class VexRenderer;
	class VertexBufferLayout;
}

class CameraController;
struct Vertex;

class ModelViewer final : public VEX::Game
{
private:
    CameraController* m_CameraController;

	VEX::Shader* m_Shader;
	VEX::Texture* m_Texture;
	VEX::Mesh* m_Mesh;

	glm::mat4 m_Transform;

	glm::vec3 m_Position;
    glm::vec3 m_Axis;
    float m_Rotation;

public:
	ModelViewer();
	~ModelViewer();

protected:
	void Start() override;
	void Input(const VEX::Window* window, VEX::Camera* camera) override;
	void Update(float delta) override;
	void Render(const VEX::VexRenderer* renderer) override;
	void Dispose() override;

private:
    void RenderUI();
    void SetupShader();
    void SetupModel();
};


