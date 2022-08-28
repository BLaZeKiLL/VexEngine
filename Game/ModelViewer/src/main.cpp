#include "Vex/Vex.h"

#include "ModelViewer.h"

int main(int, char**)
{
	VEX::VexEngine::Bootstrap(
		VEX::VexEngineConfig {
			VEX::WindowConfig { "Model Viewer", 1920, 1080, false, true},
			VEX::RendererConfig {
				glm::vec4(0.2f, 0.4f, 0.8f, 1.0f),
				VEX::CameraConfig {
					VEX::CameraProjection::PERSPECTIVE,
                    1920.0f, 1080.0f
				}
			},
			new ModelViewer()
		}
	);

	return 0;
}
