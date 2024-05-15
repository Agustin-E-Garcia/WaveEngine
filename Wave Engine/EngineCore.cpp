#include "EngineCore.h"
#include<iostream>
#include "RenderingManager.h"

void EngineCore::Initialize(const char* title)
{
	_title = title;
	_activeScene = new Scene();
}

void EngineCore::Loop()
{
	Window window;
	window.Initialize(1920, 1080, _title);

	RenderingManager renderer;
	renderer.Initialize(window);

	while (!window.ShouldClose())
	{
		window.PollEvents();
		renderer.Draw(*_activeScene);
	}

	window.Shutdown();
}

void EngineCore::SetActiveScene(Scene* scene)
{
	_activeScene = scene;
}