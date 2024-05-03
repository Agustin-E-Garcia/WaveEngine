#include "Window.h"

Window::Window() : _window(nullptr) {}

Window::~Window() {}

bool Window::Initialize(int width, int height, const char* title)
{
	if (!glfwInit()) return false;

	glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
	_window = glfwCreateWindow(width, height, title, nullptr, nullptr);
}

void Window::Shutdown()
{
	if (_window) glfwDestroyWindow((GLFWwindow*)_window);
	glfwTerminate();
}

bool Window::ShouldClose()
{
	if (_window) return glfwWindowShouldClose((GLFWwindow*)_window);
	return true;
}

void Window::PollEvents()
{
	glfwPollEvents();
}