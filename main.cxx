#include "glfw3.h"
#include "CRender.hxx"
#include "CPicture.hxx"
#include "CGraph.hxx"
#include "CModificators.hxx"
#include "TimFunction.hxx"
#include <iostream>
#include <fstream>

using namespace std;

bool _Running = true;
GLFWwindow* window;
CRender* render;
CPicture* picture;
CGraph* graph;
IFunction* graphicFunction;
IModificator* modificator1;
IModificator* modificator2;


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
	const float delta = 2; 
	for (int i = 0; i < 1; i++)
	{
		picture->Update();
		modificator1->ChangeParam(delta);
		modificator2->ChangeParam(-delta);
	}
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
	graph = new CGraph();
	graphicFunction = new JorFunction();
	modificator1 = new CMoveRightModificator();
	modificator2 = new CMoveRightModificator();

	{
		fstream input;
		input.open("input.txt", std::fstream::in);

		if (input.is_open())
		{
			graph->ReadFromFile(input);
			graphicFunction->ReadFromStream(input);
			picture->ReadBackgroundFunctions(input);
		};

		input.close();
	};

	picture->SetFunction(graphicFunction);
	picture->SetGraph(graph);
	picture->AddModificator(modificator1);
	picture->AddModificator(modificator2);
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

	delete picture;
	delete graph;
	delete render;
	delete modificator1;
	delete modificator2;

	return 0;
}
