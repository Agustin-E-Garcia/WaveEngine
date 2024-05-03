#pragma once
#include "Window.h"

class EngineCore
{
private:
	const char* _title;
public:
	void Initialize(const char* title);
	void Loop();
};