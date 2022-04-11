#include "Vex/Libs.h"
#include "Vex/Core.h"
#include "Vex/Runtime.h"
#include "Vex/Renderer.h"

#include "ModelViewer.h"

int main(int, char**)
{
	// string literals in c++ are const char * NOT strings
	const std::string title = "Model Viewer";

	VEX::VexEngine::Bootstrap(
		VEX::VexEngineConfig {
			VEX::WindowConfig { title, 1280, 720, false},
			VEX::RendererConfig { glm::vec4(0.2f, 0.4f, 0.8f, 1.0f) },
			new ModelViewer()
		}
	);

	return 0;
}
