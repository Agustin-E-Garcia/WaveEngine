#pragma once
#include <GLFW/glfw3.h>

class Window
{
private:
	void* _window;

public:
	Window();
	~Window();

	bool Initialize(int width, int height, const char* title);
	void Shutdown();
	bool ShouldClose();
	void PollEvents();

	operator GLFWwindow*() { return (GLFWwindow*)_window; }
};