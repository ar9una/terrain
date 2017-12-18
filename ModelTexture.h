
#pragma once
class ModelTexture
{
private:
	int textureID;

public:
	ModelTexture()
	{
		
	}
	ModelTexture(int id)
	{
		this->textureID = id;
	}

	int getID()
	{
		return this->textureID;
	}
};