#pragma once
#include "Header.h"
class DisplayManager
{
private:
	const int WIDTH = 1280;
	const int HEIGHT = 720;
	const int FPS_CAP = 120;

	GLFWwindow* window;

public:
	void createDisplay(char* title)
	{
		glfwInit();
		window = glfwCreateWindow(WIDTH, HEIGHT, title, NULL, NULL);
		if (window == NULL)
		{
			std::cout << "Failed to create GLFW window" << std::endl;
			glfwTerminate();
			
		}
		glfwMakeContextCurrent(window);
		

		

	}

	void SetViewport()
	{
		glViewport(0, 0, WIDTH, HEIGHT);
	}

	void glFunc()
	{
		glewExperimental = true;
		glewInit();
	}

	bool closewindow()
	{
		return glfwWindowShouldClose(window);
	}
	void swapBuffer()
	{
		glfwSwapBuffers(window);
	}
};
