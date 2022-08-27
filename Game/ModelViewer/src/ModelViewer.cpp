#include "Vex/Vex.h"

#include "ModelViewer.h"

VEX::VertexBufferLayout Vertex::GetLayout()
{
	VEX::VertexBufferLayout layout;

	layout.Push<float>(3); // Positions
	layout.Push<float>(2); // UV's

	return layout;
}

ModelViewer::ModelViewer() :
        m_Shader(nullptr),
        m_Texture(nullptr),
        m_Mesh(nullptr),
        m_Transform(glm::mat4(1.0f)),
        m_Position(glm::vec3(0.0f, 0.0f, -5.0f)),
        m_Axis(glm::vec3(1.0f, 1.0f, 1.0f)),
        m_Rotation(45.0f)
{
}

ModelViewer::~ModelViewer()
{
}

void ModelViewer::Start()
{
	GAME_LOG_INFO("Game Start");

	const auto* compiler = new VEX::ShaderCompiler();

	m_Shader = compiler->Compile("assets/Shaders/default.shader");

	delete compiler;

	m_Texture = new VEX::Texture("assets/Textures/codeblaze.png");

	m_Texture->Bind();
	m_Shader->Bind();

	m_Shader->SetUniform1i("u_Texture", glm::ivec1(0));

	m_Shader->Unbind();

	constexpr Vertex vertices[] = {
		Vertex { glm::vec3(-0.5f, -0.5f, -0.5f), glm::vec2(0.0f, 0.0f) },
		Vertex { glm::vec3(-0.5f,  0.5f, -0.5f), glm::vec2(0.0f, 1.0f) },
		Vertex { glm::vec3( 0.5f, -0.5f, -0.5f), glm::vec2(1.0f, 0.0f) },
		Vertex { glm::vec3( 0.5f,  0.5f, -0.5f), glm::vec2(1.0f, 1.0f) },

        Vertex { glm::vec3(-0.5f, -0.5f, 0.5f), glm::vec2(0.0f, 0.0f) },
        Vertex { glm::vec3(-0.5f,  0.5f, 0.5f), glm::vec2(0.0f, 1.0f) },
        Vertex { glm::vec3( 0.5f, -0.5f, 0.5f), glm::vec2(1.0f, 0.0f) },
        Vertex { glm::vec3( 0.5f,  0.5f, 0.5f), glm::vec2(1.0f, 1.0f) },

        Vertex { glm::vec3(-0.5f, -0.5f, -0.5f), glm::vec2(0.0f, 0.0f) },
        Vertex { glm::vec3(-0.5f, -0.5f,  0.5f), glm::vec2(0.0f, 1.0f) },
        Vertex { glm::vec3( 0.5f,-0.5f, -0.5f), glm::vec2(1.0f, 0.0f) },
        Vertex { glm::vec3( 0.5f, -0.5f, 0.5f), glm::vec2(1.0f, 1.0f) },

        Vertex { glm::vec3(-0.5f, 0.5f, -0.5f), glm::vec2(0.0f, 0.0f) },
        Vertex { glm::vec3(-0.5f,  0.5f, 0.5f), glm::vec2(0.0f, 1.0f) },
        Vertex { glm::vec3( 0.5f, 0.5f, -0.5f), glm::vec2(1.0f, 0.0f) },
        Vertex { glm::vec3( 0.5f,  0.5f, 0.5f), glm::vec2(1.0f, 1.0f) },

        Vertex { glm::vec3(-0.5f, -0.5f, -0.5f), glm::vec2(0.0f, 0.0f) },
        Vertex { glm::vec3(-0.5f, -0.5f,  0.5f), glm::vec2(0.0f, 1.0f) },
        Vertex { glm::vec3(-0.5f,0.5f, -0.5f), glm::vec2(1.0f, 0.0f) },
        Vertex { glm::vec3(-0.5f, 0.5f, 0.5f), glm::vec2(1.0f, 1.0f) },

        Vertex { glm::vec3(0.5f, -0.5f, -0.5f), glm::vec2(0.0f, 0.0f) },
        Vertex { glm::vec3(0.5f,  -0.5f, 0.5f), glm::vec2(0.0f, 1.0f) },
        Vertex { glm::vec3(0.5f, 0.5f, -0.5f), glm::vec2(1.0f, 0.0f) },
        Vertex { glm::vec3(0.5f,  0.5f, 0.5f), glm::vec2(1.0f, 1.0f) },
	};

	constexpr unsigned int indices[] = {
		0, 1, 2,
		2, 1, 3,

        4, 5, 6,
        6, 5, 7,

        8, 9, 10,
        10, 9, 11,

        12, 13, 14,
        14, 13, 15,

        16, 17, 18,
        18, 17, 19,

        20, 21, 22,
        22, 21, 23,
	};

	auto layout = Vertex::GetLayout();

	m_Mesh = new VEX::Mesh(layout, vertices, 24, indices, 36);
}

void ModelViewer::Input(const VEX::Window* window, VEX::Camera* camera)
{
	if (window->GetKeyAction(GLFW_KEY_ESCAPE) == GLFW_PRESS) {
		window->Close();
	}

    // Camera - Keyboard
    float speed = 2.5f * window->GetDeltaTime();

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

        camera->Look(x_pos, y_pos, 0.1f);
    } else {
        camera->LookReset();
    }
}

void ModelViewer::Update(float delta)
{

}

void ModelViewer::Render(const VEX::VexRenderer* renderer)
{
	renderer->Render(
		m_Mesh,
		m_Shader,
		glm::rotate(
			glm::translate(m_Transform, m_Position),
			glm::radians(m_Rotation),
			glm::normalize(m_Axis)
		)
	);

	ImGui::Begin("Model Viewer");

	ImGui::Text("Welcome to Model Viewer");
	ImGui::InputFloat3("Position", glm::value_ptr(m_Position));
	ImGui::SliderFloat3("Axis", glm::value_ptr(m_Axis), 0.0f, 1.0f);
	ImGui::SliderFloat("Rotation", &m_Rotation, 0.0f, 360.0f);
	ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);

	ImGui::End();
}

void ModelViewer::Dispose()
{
	delete m_Mesh;
	delete m_Texture;
	delete m_Shader;

	GAME_LOG_INFO("Game Dispose");
}
