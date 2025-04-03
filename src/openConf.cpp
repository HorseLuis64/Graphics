#include "openConf.h"


//_-_-_-_-_-_-SHADER CLASS_-_-_-_-_-_-_-

namespace opg
{
	void checkShaderCompilation(unsigned int shader);
	void checkProgramLinking(unsigned int program);

	Shader::Shader(const char* vShaderPat, const char* fShaderPat) : vShaderPath(vShaderPat), fShaderPath(fShaderPat)
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
		checkShaderCompilation(vertexShader);

		fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
		glShaderSource(fragmentShader, 1, &fShaderSource, NULL);
		glCompileShader(fragmentShader);
		checkShaderCompilation(fragmentShader);

	}

	void Shader::createShaderProgram(unsigned int &shaderProgram)
	{
		shaderProgram = glCreateProgram();
		glAttachShader(shaderProgram, vertexShader);
		glAttachShader(shaderProgram, fragmentShader);
		glLinkProgram(shaderProgram);
		checkProgramLinking(shaderProgram);
	
		this->id = shaderProgram;

		glDeleteShader(vertexShader);
		glDeleteShader(fragmentShader);
	}

	unsigned int Shader::getVertex()
	{
		return vertexShader;
	}

	unsigned int Shader::getFragment()
	{
		return fragmentShader;
	}

	unsigned int Shader::Id(){return id;}

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

}


//GLFW__WINDOW__CONFIGURATIONS----------------


namespace opg 
{

	//thanks gpt
	//{
	void checkShaderCompilation(unsigned int shader)
	{
		int success;
		char infoLog[512];
		glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(shader, 512, NULL, infoLog);
			std::cerr << "ERROR::SHADER::COMPILATION_FAILED\n" << infoLog << std::endl;
		}
	}

	void checkProgramLinking(unsigned int program)
	{
		int success;
		char infoLog[512];
		glGetProgramiv(program, GL_LINK_STATUS, &success);
		if (!success)
		{
			glGetProgramInfoLog(program, 512, NULL, infoLog);
			std::cerr << "ERROR::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
		}
	}
	//}

	
	
	void framebuffer_size_callback(GLFWwindow* window, int width, int height)
	{
		glViewport(0, 0, width, height);
	}


	GLFWwindow* glfwConfiguration(int a, int b, int c , int d )
	{
		if(c || d == 0)
		{
			c = a;
			d = b;
		}
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
		glViewport(0, 0, a, b);

		//indicate opengl this is the funcion to resize a window, fill automatic other parameters
		//abstraction
		//glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);


		return window;
	}
}