#include "glfw3.h"
#include "CRender.hxx"
#include "CPicture.hxx"
#include "TimFunction.hxx"

bool _Running = true;
GLFWwindow* window;
CRender* render;
CPicture* picture;

void KeyboardCallback(GLFWwindow *window, int key, int scan, int action, int mods)
{
	if ((key == GLFW_KEY_ESCAPE) && (action == GLFW_PRESS))
		_Running = false;
}

void Render()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	render->DrawPicture(picture);

	glfwPollEvents();
	glfwSwapBuffers(window);
}

void Update()
{
}

void InitProjection()
{
	int width, height;
	glfwGetFramebufferSize(window, &width, &height);
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, 1, 0, 1, -1, 1);
	glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char const *argv[])
{
	glfwInit();
	
	render = new CRender();
	picture = new CPicture();
	picture->SetFunction(new JorFunction());
	picture->Init();
	
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
