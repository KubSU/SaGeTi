#include "glfw3.h"

bool _Running = true;
GLFWwindow* window;


void KeyboardCallback(GLFWwindow *window, int key, int scan, int action, int mods)
{
	if ((key == GLFW_KEY_ESCAPE) && (action == GLFW_PRESS))
		_Running = false;
}

void Render()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	

	glfwPollEvents();
	glfwSwapBuffers(window);
}

void Update()
{

}

void InitProjection()
{
	float ratio;
	int width, height;
	glfwGetFramebufferSize(window, &width, &height);
	ratio = width / (float) height;
	glViewport(0, 0, width, height);
}

int main(int argc, char const *argv[])
{
	glfwInit();

	window = glfwCreateWindow(600, 600, "GL window", NULL, NULL);
	glfwMakeContextCurrent(window);

	InitProjection();
	glfwSetKeyCallback(window, KeyboardCallback);

	while ((_Running) && !glfwWindowShouldClose(window))
	{
		Render();
		Update();
	}

	glfwTerminate();
	return 0;
}