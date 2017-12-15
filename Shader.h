#pragma once
#include <GL\glew.h>
#include<GLFW\glfw3.h>

class Shader
{
private:

	int programID, vertexShaderID,fragmentShaderID;

	Shader(char* vertexFile, char* fragmentFile)
	{
		vertexShaderID = loadShader(vertexFile, GL_VERTEX_SHADER);
		fragmentShaderID = loadShader(vertexFile, GL_FRAGMENT_SHADER);
		programID = glCreateProgram();

		glAttachShader(programID, vertexShaderID);
		glAttachShader(programID, fragmentShaderID);

		glLinkProgram(programID);
		glValidateProgram(programID);
	}
	void bindAttributes()
	{

	}

	void start() {
		glUseProgram(programID);
	}

	void stop()
	{
		glUseProgram(0);
	}
	
	int loadShader(char* file, int type)
	{

	}
	
};