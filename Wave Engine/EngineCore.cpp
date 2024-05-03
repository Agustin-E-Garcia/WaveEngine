#include "EngineCore.h"
#include<iostream>
#include "RenderingManager.h"

void EngineCore::Initialize(const char* title)
{
	_title = title;
}

void EngineCore::Loop()
{
	Window window;
	window.Initialize(800, 600, _title);

	RenderingManager renderer;
	renderer.Initialize(window);

	while (!window.ShouldClose())
	{
		window.PollEvents();
		renderer.Loop();
	}

	window.Shutdown();
}