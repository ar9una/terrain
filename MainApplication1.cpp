#include "Header.h"

GLFWwindow *window;
DisplayManager o_displayManager;
Shader o_shader;
int main()
{
	o_displayManager.createDisplay("Terrain creation");
	o_displayManager.SetViewport();
	o_displayManager.glFunc();
	//glewExperimental = true;
	//glewInit();

	BufferLoader *o_bufferLoader = new BufferLoader();

	Renderer o_renderer;
	Entity o_entity;

	std::vector<float> positions;
	std::vector<int> indices;
	std::vector <float> Textcoord;

	positions.push_back(-0.5);
	positions.push_back(0.5);
	positions.push_back(0);

	Textcoord.push_back(0.0);
	Textcoord.push_back(0.0);

	positions.push_back(-0.5);
	positions.push_back(-0.5);
	positions.push_back(0);

	Textcoord.push_back(0.0);
	Textcoord.push_back(1.0);

	positions.push_back(0.5);
	positions.push_back(-0.5);
	positions.push_back(0);

	Textcoord.push_back(1.0);
	Textcoord.push_back(1.0);

	positions.push_back(0.5);
	positions.push_back(0.5);
	positions.push_back(0);

	Textcoord.push_back(1.0);
	Textcoord.push_back(0.0);

	indices.push_back(0);
	indices.push_back(1);
	indices.push_back(3);

	indices.push_back(1);
	indices.push_back(3);
	indices.push_back(2);

	RawModel model = o_bufferLoader->loadToBuffer(positions,indices,Textcoord);
	ModelTexture o_ModelTexture(o_bufferLoader->loadTexture("./assets/Penguins.jpg"));
	TextureModels o_TextureModels(model, o_ModelTexture);
	Entity e(o_TextureModels, glm::vec3(0, 0, -5), 0, glm::vec3(0,0,0),glm::vec3(0, 1,0));
	o_shader.creatShader("./Shaders/MVP_vs.glsl", "./Shaders/MVP_fs.glsl");
	Camera c;
	//RawModel model = o_bufferLoader.loadToBuffer(positions);
	while (!o_displayManager.closewindow())
	{
		o_renderer.prepare();
		o_shader.start();
		o_renderer.render(o_TextureModels);
		o_shader.stop();

		glfwPollEvents();
		o_displayManager.swapBuffer();

	}
	o_shader.cleanUP();
	//o_renderer.releaseMemory(o_TextureModels);
	o_displayManager.closewindow();


	return 0;
}