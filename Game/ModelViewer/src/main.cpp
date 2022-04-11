#include "Vex/Vex.h"

#include "ModelViewer.h"

int main(int, char**)
{
	VEX::VexEngine::Bootstrap(
		VEX::VexEngineConfig {
			VEX::WindowConfig { "Model Viewer", 1280, 720, false},
			VEX::RendererConfig { glm::vec4(0.2f, 0.4f, 0.8f, 1.0f) },
			new ModelViewer()
		}
	);

	return 0;
}
