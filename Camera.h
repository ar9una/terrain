#pragma once
#include "header.h"

#define MAX_VERTICAL_ANGLE 85

class Camera {
private:
	glm::vec3 m_position;
	float m_aspectratio, m_nearplane, m_farplane, m_FOV, m_horizontalAngle, m_verticalAngle;

	void normalizeAngles()
	{
		m_horizontalAngle = fmodf(m_horizontalAngle, 360.0f);
		if (m_horizontalAngle < 0.0f)
		{
			m_horizontalAngle += 360.0f;
		}
		if (m_verticalAngle > MAX_VERTICAL_ANGLE)
		{
			m_verticalAngle = MAX_VERTICAL_ANGLE;
		}
		else if (m_verticalAngle < -MAX_VERTICAL_ANGLE)
		{
			m_verticalAngle = -MAX_VERTICAL_ANGLE;
		}
	}

public:

	glm::mat4 orientation();
	glm::mat4 modelMatrix();
	glm::mat4 projectionMatrix();
	glm::mat4 viewMatrix();
	glm::mat4 mvpMatrix();

	Camera()
	{
		m_position = glm::vec3(0.0, 0.0, 100.0);
		m_horizontalAngle = 0.0;
		m_verticalAngle = 0.0;
		m_FOV = 45.0;
		m_nearplane = 0.1;
		m_farplane = 1000;
		m_aspectratio = 4.0 / 3.0f;
	}


	~Camera()
	{
	}

	void setPosition(glm::vec3 position)
	{
		m_position = position;
	}

	const glm::vec3& GetPosition()
	{
		return m_position;
	}

	void SetFOV(float FOV)
	{
		m_FOV = FOV;
	}
	const float GetFOV()
	{
		return m_FOV;
	}

	void LookAt(glm::vec3 direction)
	{
		assert(m_position != direction);
		glm::vec3 location = glm::normalize(direction - m_position);
		m_verticalAngle = glm::radians(asinf(-location.y));
		m_horizontalAngle = -glm::radians(atan2f(-location.x, location.z));
		normalizeAngles();
	}



	glm::mat4 orientation()
	{
		glm::mat4 orientation;
		orientation = glm::rotate(orientation, glm::radians(m_verticalAngle), glm::vec3(1, 0, 0));
		orientation = glm::rotate(orientation, glm::radians(m_horizontalAngle), glm::vec3(0, 1, 0));
		return orientation;
	}

	glm::mat4 modelMatrix()
	{
		glm::mat4 retVal;
		return retVal;
	}

	glm::mat4 projectionMatrix()
	{
		return glm::perspective(glm::radians(m_FOV), m_aspectratio, m_nearplane, m_farplane);
	}

	glm::mat4 viewMatrix()
	{
		return orientation() *glm::translate(glm::mat4(), -m_position);
	}

	glm::mat4 mvpMatrix()
	{
		return modelMatrix()*projectionMatrix()*viewMatrix();
	}

};