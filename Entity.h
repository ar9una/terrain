#pragma once
#include "Header.h"
class Entity {  //renderObject

private:
	TextureModels model;
	glm::vec3 position;
	float rotate;
	glm::vec3 scale;
	glm::vec3 rotateAxis;

	glm::mat4 m_translateMat, m_scaleMat, m_rotateMat;


public:
	Entity()
	{

	}
	Entity(TextureModels model, glm::vec3 position, float rotate, glm::vec3 scale, glm::vec3 rotateAxis)
	{
		this->model = model;
		this->position = position;
		this->scale = scale;
		this->rotate = rotate;
		this->rotateAxis = rotateAxis;
	}

	void MovePosition(float x,float y,float z)
	{
		position.x += x;
		position.y += y;
		position.z += z;
	}

	void rotate(float x, float y, float z)
	{
		rotateAxis.x = x;
		rotateAxis.y = y;
		rotateAxis.z = z;
	}

	TextureModels getTextureModel()
	{
		return model;
	}

	glm::vec3 getPosition()
	{
		return position;
	}

	glm::vec3 getScaling()
	{
		return scale;
	}
	


	void update(float deltaTime)
	{
		rotate += 1.0f * deltaTime;
	}

	void updateMatrices()
	{
		glm::mat4 identityMat(1.0f);
		m_translateMat = glm::translate(identityMat, position);
		m_scaleMat = glm::scale(identityMat, scale);
		m_rotateMat = glm::rotate(identityMat, rotate, rotateAxis);
	}

	glm::mat4& getTranslateMatrix()
	{
		return m_translateMat;
	}

	glm::mat4& getScalingMatrix()
	{
		return m_scaleMat;
	}

	glm::mat4& getRotateMatrix()
	{
		return m_rotateMat;
	}

	

	
};