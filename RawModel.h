#pragma once
class RawModel
{
private:
	int vaoId;
	int vertexCount;

public:
	RawModel()
	{

	}
	RawModel(int vaoID, int vertexCount)
	{
		this->vaoId = vaoID;
		this->vertexCount = vertexCount;

	}

	int getVaoID()
	{
		return vaoId;
	}

	int getVertexCount()
	{
		return vertexCount;
	}

};