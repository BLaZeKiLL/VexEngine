#include "Core.h"
#include "Runtime.h"

#include "ModelViewer.h"

int main(int, char**)
{
	// string literals in c++ are const char * NOT strings
	const std::string title = "Model Viewer";

	const auto engine = new VEX::VexEngine(
		VEX::VexEngineConfig {
			VEX::WindowConfig { title, 1280, 720, false},
			new ModelViewer()
		}
	);

	engine->Start();

	delete engine;

	return 0;
}
