#pragma once
#include <GLFW/glfw3.h>

class Window
{
private:
	const char* _title;
	void* _window;

public:
	Window();
	~Window();

	bool Initialize(int width, int height, const char* title);
	void Shutdown();
	bool ShouldClose();
	void PollEvents();

	const char* GetTitle() { return _title; }

	operator GLFWwindow*() { return (GLFWwindow*)_window; }
};