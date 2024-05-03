#include <iostream>
#include "EngineCore.h"

int main()
{
	EngineCore engine;
	engine.Initialize("Vulkan Test");

	try
	{
		engine.Loop();
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}