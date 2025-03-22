#include "openConf.h"
namespace opg 
{

	Shader::Shader(const char* vShaderPath, const char* fShaderPath, unsigned int* shaderProgram) : vShaderPath(vShaderPath), fShaderPath(fShaderPath), shaderProgram(shaderProgram)
	{
		createShaders();
	}
	
	Shader::~Shader()
	{

	}

	void Shader::createShaders()
	{
		std::string vPath = loadShaderSource(vShaderPath);
		std::string fPath = loadShaderSource(fShaderPath);
		
		vShaderSource = vPath.c_str();
		fShaderSource = fPath.c_str();

		vertexShader = glCreateShader(GL_VERTEX_SHADER);
		glShaderSource(vertexShader, 1, &vShaderSource, NULL);
		glCompileShader(vertexShader);

		fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
		glShaderSource(fragmentShader, 1, &fShaderSource, NULL);
		glCompileShader(fragmentShader);

		*shaderProgram = glCreateProgram();
		glAttachShader(*shaderProgram, vertexShader);
		glAttachShader(*shaderProgram, fragmentShader);
		glLinkProgram(*shaderProgram);

		glDeleteShader(vertexShader);
		glDeleteShader(fragmentShader);
	}
	std::string loadShaderSource(const char* filePath) {
		std::ifstream file(filePath);
		if (!file.is_open()) {
			std::cerr << "Error al abrir el archivo de shader: " << filePath << std::endl;
			return "";
		}
	
		std::stringstream buffer;
		buffer << file.rdbuf();
		file.close();
		return buffer.str();
	}
	
	void framebuffer_size_callback(GLFWwindow* window, int width, int height)
	{
		glViewport(0, 0, width, height);
	}


	GLFWwindow* glfwConfiguration(int a, int b)
	{
		glfwInit();
		//configure aspects of glfw, first argument the option, second the setting
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);



		GLFWwindow* window = glfwCreateWindow(a, b, "VENTANITA WOO", NULL, NULL);
		if (window == NULL)
		{
			std::cout << "kkkk";
			glfwTerminate();
			
		}

		glfwMakeContextCurrent(window);


		//opengl its just a reference api, glad take charge of send the references of
		// the functions to the OS specific libraries, and opengl acces it, glfw send the 
		//specific references
		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
			std::cerr << "Failed to initialize GLAD" << std::endl;
		}
	


		//tells opengl the area of rendering
		glViewport(0, 0, 800, 800);

		//indicate opengl this is the funcion to resize a window, fill automatic other parameters
		//abstraction
		//glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);


		return window;
	}
}