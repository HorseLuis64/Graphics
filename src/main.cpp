#include "openConf.h"



const char* vertexShaderSource = "#version 330 core \n"
"layout (location = 0) in vec3 aPos; \n"
"void main()\n"
"{\n"
"	glPosition = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
"}\0";

const char* fragmentShaderSource = "#version 330 core \n"
"out vec4 FragColor;\n"
"void main()\n"
"{\n"
"	Frag4 = vec4(0.9f, 0.1f, 0.1f, 1.0f);\n"
"}\0";
/*
* This is a way of doing it, but, its correctly in the official mode
void changeWindowRenderSize(GLFWwindow* window, int width, int height)
{
	glfwSetWindowSize(window, width, height);
	glViewport(0, 0, width, height);
}*/

float vertices[] =
{
	-0.5f, -0.5f, 0.0f,
	0.0f, 0.5f, 0.0f,
	0.5f, -0.5f, 0.0f
};

//function to resize window



void takeInput(GLFWwindow* window)
{
	//mayority of macros are integers
	if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(window, true);
	}
}


int main()
{

	GLFWwindow* window = opg::glfwConfiguration();
	
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	//initializacion and definition of the vertex shader
	unsigned int vertexShader;
	vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
	glCompileShader(vertexShader);

	//initializacion and definition of the fragment shader
	unsigned int fragmentShader;
	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
	glCompileShader(fragmentShader);
	
	//main window loop, cmon you know this
	while (!glfwWindowShouldClose(window))
	{
		//----------INPUTE MANAGE----------
		takeInput(window);
		//checks if any event have done, input

		//----------TODO: PHYSICS---------


		//-------RENDERING----------
		glClearColor(0.12f, 0.45f, 0.7f, 0.9f);
		glClear(GL_COLOR_BUFFER_BIT);


		//---------OUTPUT----------
		glfwSwapBuffers(window);
		//replace the actualbuffer to the next buffer, exchanges the color pixels
		// to the ones that had been saved in memory
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}