#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

class glfw_window
{
public:
	void init(int width, int height, const std::string& title);

	void clear();

	void swapBuffers();

	void events();

	bool isClosed();

	void delete_window();

	bool* get_keys();
private:
	GLFWwindow* m_window;
	bool m_keys[1024];
	static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);
};

