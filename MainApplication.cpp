//#include "Header.h"
//
//GLFWwindow *window;
//DisplayManager o_displayManager;
//int main()
//{
//	o_displayManager.createDisplay("Terrain creation");
//	o_displayManager.SetViewport();
//	o_displayManager.glFunc();
//	//glewExperimental = true;
//	//glewInit();
//
//	BufferLoader *o_bufferLoader = new BufferLoader();
//
//	Renderer o_renderer;
//
//	std::vector<float> positions;
//
//	
//	positions.push_back(-0.5);
//	positions.push_back(-0.5);
//	positions.push_back(0);
//
//	positions.push_back(-0.5);
//	positions.push_back(0.5);
//	positions.push_back(0);
//
//	positions.push_back(0.5);
//	positions.push_back(0.5);
//	positions.push_back(0);
//
//	//right bottom traingle
//	positions.push_back(-0.5);
//	positions.push_back(-0.5);
//	positions.push_back(0);
//
//
//	positions.push_back(0.5);
//	positions.push_back(0.5);
//	positions.push_back(0);
//
//
//	positions.push_back(0.5);
//	positions.push_back(-0.5);
//	positions.push_back(0);
//	
//
//	RawModel* model = o_bufferLoader->loadToBuffer(positions);
//	//RawModel model = o_bufferLoader.loadToBuffer(positions);
//	while (!o_displayManager.closewindow())
//	{
//		o_renderer.prepare();
//
//		o_renderer.render(model);
//
//		
//		glfwPollEvents();
//		o_displayManager.swapBuffer();
//
//	}
//
//	o_renderer.releaseMemory(model);
//	o_displayManager.closewindow();
//		
//
//	return 0;
//}