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
	class VertexBufferLayout;
}

struct Vertex
{
	glm::vec3 Position;
	glm::vec2 UV0;

	static VEX::VertexBufferLayout GetLayout();
};

class ModelViewer final : public VEX::Game
{
private:
	VEX::Shader* m_Shader;
	VEX::Texture* m_Texture;
	VEX::Mesh* m_Mesh;

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


