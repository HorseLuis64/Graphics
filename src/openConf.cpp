#include "openConf.h"
namespace opg 
{
	
	void framebuffer_size_callback(GLFWwindow* window, int width, int height)
	{
		glViewport(0, 0, width, height);
	}


	GLFWwindow* glfwConfiguration()
	{
		glfwInit();
		//configure aspects of glfw, first argument the option, second the setting
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);



		GLFWwindow* window = glfwCreateWindow(800, 800, "VENTANITA WOO", NULL, NULL);
		if (window == NULL)
		{
			std::cout << "kkkk";
			glfwTerminate();
			
		}

		glfwMakeContextCurrent(window);


		//opengl its just a reference api, glad take charge of send the references of
		// the functions to the OS specific libraries, and opengl acces it, glfw send the 
		//specific references
		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		{
			glfwTerminate();
			
		}


		//tells opengl the area of rendering
		glViewport(0, 0, 800, 800);

		//indicate opengl this is the funcion to resize a window, fill automatic other parameters
		//abstraction
		//glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);


		return window;
	}
}