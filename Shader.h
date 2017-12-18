#pragma once
#include "Header.h"

class Shader
{
private:

	int shaderID;
	GLuint VertexShaderID, FragmentShaderID;
	int m_textureLocation, m_translateMatrixLocation, m_rotateMatrixLocation, m_scaleMatrixLocation, m_viewMatrixLocation;

public:

	bool creatShader(char* vertexFile, char* fragmentFile)
	{
		bool retVal = true;

		// Create the shaders
	    VertexShaderID = glCreateShader(GL_VERTEX_SHADER);
		FragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);

		// Read the Vertex Shader code from the file
		std::string VertexShaderCode;
		std::ifstream VertexShaderStream(vertexFile, std::ios::in);
		if (VertexShaderStream.is_open()) {
			std::string Line = "";
			while (getline(VertexShaderStream, Line))
				VertexShaderCode += "\n" + Line;
			VertexShaderStream.close();
		}
		else {
			printf("Impossible to open %s. Are you in the right directory ? Don't forget to read the FAQ !\n", vertexFile);
			getchar();
			return 0;
		}

		// Read the Fragment Shader code from the file
		std::string FragmentShaderCode;
		std::ifstream FragmentShaderStream(fragmentFile, std::ios::in);
		if (FragmentShaderStream.is_open()) {
			std::string Line = "";
			while (getline(FragmentShaderStream, Line))
				FragmentShaderCode += "\n" + Line;
			FragmentShaderStream.close();
		}



		GLint Result = GL_FALSE;
		int InfoLogLength;



		// Compile Vertex Shader
		printf("Compiling shader : %s\n", vertexFile);
		char const * VertexSourcePointer = VertexShaderCode.c_str();
		glShaderSource(VertexShaderID, 1, &VertexSourcePointer, NULL);
		glCompileShader(VertexShaderID);

		// Check Vertex Shader
		glGetShaderiv(VertexShaderID, GL_COMPILE_STATUS, &Result);
		glGetShaderiv(VertexShaderID, GL_INFO_LOG_LENGTH, &InfoLogLength);
		if (InfoLogLength > 0) {
			std::vector<char> VertexShaderErrorMessage(InfoLogLength + 1);
			glGetShaderInfoLog(VertexShaderID, InfoLogLength, NULL, &VertexShaderErrorMessage[0]);
			printf("%s\n", &VertexShaderErrorMessage[0]);
		}



		// Compile Fragment Shader
		printf("Compiling shader : %s\n", fragmentFile);
		char const * FragmentSourcePointer = FragmentShaderCode.c_str();
		glShaderSource(FragmentShaderID, 1, &FragmentSourcePointer, NULL);
		glCompileShader(FragmentShaderID);

		// Check Fragment Shader
		glGetShaderiv(FragmentShaderID, GL_COMPILE_STATUS, &Result);
		glGetShaderiv(FragmentShaderID, GL_INFO_LOG_LENGTH, &InfoLogLength);
		if (InfoLogLength > 0) {
			std::vector<char> FragmentShaderErrorMessage(InfoLogLength + 1);
			glGetShaderInfoLog(FragmentShaderID, InfoLogLength, NULL, &FragmentShaderErrorMessage[0]);
			printf("%s\n", &FragmentShaderErrorMessage[0]);
		}

		// Link the program
		printf("Linking program\n");
		shaderID = glCreateProgram();
		glAttachShader(shaderID, VertexShaderID);
		glAttachShader(shaderID, FragmentShaderID);
		glLinkProgram(shaderID);

		// Check the program
		glGetProgramiv(shaderID, GL_LINK_STATUS, &Result);
		glGetProgramiv(shaderID, GL_INFO_LOG_LENGTH, &InfoLogLength);
		if (InfoLogLength > 0) {
			std::vector<char> ProgramErrorMessage(InfoLogLength + 1);
			glGetProgramInfoLog(shaderID, InfoLogLength, NULL, &ProgramErrorMessage[0]);
			printf("%s\n", &ProgramErrorMessage[0]);
		}

		glDeleteShader(VertexShaderID);
		glDeleteShader(FragmentShaderID);

		bindAttributes();
		return retVal;
	}
	void bindAttributes()
	{

		m_textureLocation = glGetUniformLocation(shaderID, "texture");
		m_translateMatrixLocation = glGetUniformLocation(shaderID, "translate");
		m_rotateMatrixLocation = glGetUniformLocation(shaderID, "rotate");
		m_scaleMatrixLocation = glGetUniformLocation(shaderID, "scale");
		m_viewMatrixLocation = glGetUniformLocation(shaderID, "view");

	}

	void start() {
		glUseProgram(shaderID);
	}

	void stop()
	{
		glUseProgram(0);
	}
	void cleanUP()
	{
		glDetachShader(shaderID, VertexShaderID);
		glDetachShader(shaderID, FragmentShaderID);
		glDeleteShader(VertexShaderID);
			glDeleteShader(FragmentShaderID);
		glDeleteProgram(shaderID);
	}

	int getTextureLocation()
	{
		return m_textureLocation;
	}

	int getViewMatrixLocation()
	{
		return m_viewMatrixLocation;
	}

	int getTranslateMatrixLocation()
	{
		return m_translateMatrixLocation;
	}

	int getRotateMatrixLocation()
	{
		return m_rotateMatrixLocation;
	}

	int getScaleMatrixLocation()
	{
		return m_scaleMatrixLocation;
	}
	
	
	
	
};