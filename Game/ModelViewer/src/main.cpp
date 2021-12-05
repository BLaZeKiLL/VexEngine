#include "Core.h"
#include "Runtime.h"

#include "ModelViewer.h"

int main(int, char**)
{
	// string literals in c++ are const char * NOT strings
	const std::string title = "Model Viewer";

	const auto windowConfig = VEX::WindowConfig {
		title, 1280, 720, false
	};

	const auto game = new ModelViewer();

	const auto engine = new VEX::VexEngine(VEX::VexEngineConfig {windowConfig, game});

	engine->Start();

	delete engine;

	return 0;
}
