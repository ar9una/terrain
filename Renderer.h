#pragma once
#include "Header.h"
class Renderer
{
public:
	void prepare()
	{
		glClearColor(1, 0.5, 0.5, 1);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}
	void render(RawModel* model)
	{
		glBindVertexArray(model->getVaoID());
		glEnableVertexArrayAttrib(model->getVaoID(), 1);
		glDrawArrays(GL_TRIANGLES, 0, model->getVertexCount()*3);
		
		//glDrawElements(GL_TRIANGLES, model->getVertexCount()*3, GL_UNSIGNED_INT, 0);
		/*glDisableVertexArrayAttrib(model->getVaoID(),0);
		glBindVertexArray(0);*/

	}

	void releaseMemory(RawModel* model)
	{
		/*glDisableVertexArrayAttrib(model->getVaoID(),0);
		glBindVertexArray(0);*/
	}
};