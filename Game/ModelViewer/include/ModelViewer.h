#pragma once

#include "Vex/Math.h"
#include "Vex/Runtime.h"

namespace VEX
{
	class Mesh;
	class Shader;
	class Window;
	class Texture;
	class VexRenderer;
}

class ModelViewer final : public VEX::Game
{
private:
	VEX::Shader* m_Shader;
	VEX::Texture* m_Texture;
	VEX::Mesh* m_Mesh;

	glm::mat4 m_Projection;
	glm::mat4 m_View;
	glm::mat4 m_Model;

	glm::vec3 m_Position;
public:
	ModelViewer();
	~ModelViewer();
protected:
	void Start() override;
	void Input(const VEX::Window* window) override;
	void Update(float delta) override;
	void Render(const VEX::VexRenderer* renderer) override;
	void Dispose() override;
};


