#pragma once
#include "Window.h"
#include "Scene.h"

class EngineCore
{
private:
	const char* _title;
	Scene* _activeScene;
public:
	void Initialize(const char* title);
	void Loop();

	void SetActiveScene(Scene* scene);
};