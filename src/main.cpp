#include "openConf.h"


//@HorseLuis64 omla
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
	
	//creation of shader program, combines all the shaders to render
	unsigned int shaderProgram;
	shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	glLinkProgram(shaderProgram);

	//apparantely, when we attatch the shader, it creates a copy, so
	//we no longer need the original ones
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);

	
	//VERTEX BUFFER OBJECT AND VERTEX ARRAY OBJECT
	unsigned int VBO, VAO;
	glGenBuffers(1, &VBO);
	glGenVertexArrays(1, &VAO);

	//first bind the vertex array, because well, it will be attached later to VBO
	glBindVertexArray(VAO);

	//make the gl_array_buffer the vbo
	//0.copy out vertices array in a buffer for Opengl to use
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);


	//indicate opengl how to treat the data is in the shaders
	//1.then set the vertex attribute pointers
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
	//2.Use our shader program when we want to render an object
	

	
	//main window loop, cmon you know this
	while (!glfwWindowShouldClose(window))
	{
		//----------INPUTE MANAGE----------
		takeInput(window);
		//checks if any event have done, input

		//----------TODO: PHYSICS---------


		//-------RENDERING----------
		glUseProgram(shaderProgram);
		glBindVertexArray(VAO);
		glDrawArrays(GL_TRIANGLES, 0, 3);
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