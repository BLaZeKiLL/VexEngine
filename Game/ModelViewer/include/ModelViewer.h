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

class TransformData;
class LightData;
class MaterialData;

class ModelViewer final : public VEX::Game
{
private:
	VEX::Shader* m_Shader;
	VEX::Texture* m_Texture;
	VEX::Mesh* m_Mesh;

    CameraController* m_CameraController;

    TransformData* m_TransformData;
    LightData* m_LightData;
    MaterialData* m_MaterialData;

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
    void UpdateShader();
    void SetupModel();
};


