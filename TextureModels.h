#pragma once
#include "Header.h"

class TextureModels
{
private:
	RawModel o_rawModel;
	ModelTexture o_ModelTexture;

public:
	TextureModels()
	{

	}
	TextureModels(RawModel model, ModelTexture texture)
	{
		this->o_rawModel = model;
		this->o_ModelTexture = texture; 
	}

	RawModel getRawModel()
	{
		return o_rawModel;
	}

	ModelTexture getTexture()
	{
		return o_ModelTexture;
	}

};