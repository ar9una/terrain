#pragma once
#include "Header.h"

class Renderer
{
public:
	void prepare()
	{
		glClearColor(0.2941f,  0.03921f, 0.1294f, 1);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}
	void updateLocationValues(Entity renderObjectPointer)
	{
		Shader* tempShaderPtr;
		glUniform1i(tempShaderPtr->getTextureLocation(), 0);
		
		glUniformMatrix4fv(tempShaderPtr->getViewMatrixLocation(), 1, GL_FALSE, glm::value_ptr(m_pCamera->mvpMatrix()));
		glUniformMatrix4fv(tempShaderPtr->getTranslateMatrixLocation(), 1, GL_FALSE
			, glm::value_ptr(renderObjectPointer->getTranslateMatrix()));
		glUniformMatrix4fv(tempShaderPtr->getRotateMatrixLocation(), 1, GL_FALSE
			, glm::value_ptr(renderObjectPointer->getRotateMatrix()));
		glUniformMatrix4fv(tempShaderPtr->getScaleMatrixLocation(), 1, GL_FALSE
			, glm::value_ptr(renderObjectPointer->getScalingMatrix()));
	}
	void render(Entity o_entity)
	{
		o_entity.updateMatrices();
		TextureModels models = o_entity.getTextureModel();
		RawModel model = models.getRawModel();
		updateLocationValues(o_entity);
		glBindVertexArray(model.getVaoID());
		glEnableVertexArrayAttrib(model.getVaoID(), 1);
	//glEnableVertexArrayAttrib(model.getVaoID(), 2);

	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, models.getTexture().getID());
		glDrawArrays(GL_TRIANGLES, 0, model.getVertexCount()*3);
		
		glBindTexture(GL_TEXTURE_2D, 0);
		glBindVertexArray(0);
		//glDrawElements(GL_TRIANGLES, model->getVertexCount()*3, GL_UNSIGNED_INT, 0);
		/*glDisableVertexArrayAttrib(model->getVaoID(),0);

		glBindVertexArray(0);*/
		//glDisableVertexArrayAttrib(model->getVaoID(), 0);
		//glDisableVertexArrayAttrib(model->getVaoID(), 1);

	}

	void releaseMemory(RawModel* model)
	{
		/*glDisableVertexArrayAttrib(model->getVaoID(),0);
		glBindVertexArray(0);*/
	}
};