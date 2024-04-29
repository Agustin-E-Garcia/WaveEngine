#include <iostream>
#include "RenderingManager.h"

int main()
{
	RenderingManager renderer;

	try
	{
		renderer.Run();
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}