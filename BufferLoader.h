#include "header.h"


class BufferLoader
{

public:
 RawModel loadToBuffer(std::vector<float> positions, std::vector<int> indices,std::vector<float> uv) //, std::vector<float> uv, std::vector<float> normals, std::vector<int> indices)
	{
		unsigned int vaoID = createVAO();
		storeToVBO(positions, 3, 0);
		storeToVBO(uv, 2, 1);
		/*storeToVBO(normals, 3, 2);*/
		storeElementsToVBO(indices);
		return RawModel(vaoID, indices.size()*6);
	}

private:
	unsigned int createVAO()
	{
		unsigned int vaoID;
		glGenVertexArrays(1, &vaoID);
		glBindVertexArray(vaoID);
		return vaoID;
	}

	void storeToVBO(std::vector<float> data, unsigned length, unsigned int index)
	{
		unsigned int vboID;
		glGenBuffers(1, &vboID);

		float* floatBufferPtr = new float[data.size()];
		std::vector<float>::iterator current = data.begin();
		std::vector<float>::iterator end = data.end();
		for (int i = 0; current != end; current++, i++)
		{
			floatBufferPtr[i] = *current;
		}

		glBindBuffer(GL_ARRAY_BUFFER, vboID);
		glBufferData(GL_ARRAY_BUFFER, data.size() * sizeof(float), floatBufferPtr, GL_STATIC_DRAW);

		glVertexAttribPointer(index, length, GL_FLOAT, GL_FALSE, 0, (GLvoid*)0);
		glEnableVertexAttribArray(index);

		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}

	void storeElementsToVBO(std::vector<int> indices)
	{
		unsigned int vboID;
		glGenBuffers(1, &vboID);

		
		int* intBufferPtr = new int[indices.size()];
		std::vector<int>::iterator current = indices.begin();
		std::vector<int>::iterator end = indices.end();
		for (int i = 0; i < size(indices); i++)
		{
			intBufferPtr[i] = *current;
		}

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vboID);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(int), intBufferPtr, GL_STATIC_DRAW);

		glBindBuffer(GL_ARRAY_BUFFER, 0);

	}


	void unbindVAO()
	{
		glBindVertexArray(0);
	}

public:
	int loadTexture(const char* filename) {
		GLuint textureID;
		unsigned char * image;
		int width, height;

		glGenTextures(1, &textureID);
		glBindTexture(GL_TEXTURE_2D, textureID);

		//set our texture parameters
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

		//set texture filtering
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		// load,create texture and generate mipmaps
		image = SOIL_load_image(filename, &width, &height, 0, SOIL_LOAD_RGBA);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);
		glGenerateMipmap(GL_TEXTURE_2D);
		SOIL_free_image_data(image);
		glBindTexture(GL_TEXTURE_2D, 0);
		return textureID;
	}
	void cleanUP()
	{
	//	glDeleteTextures(0,tex)
	}

};