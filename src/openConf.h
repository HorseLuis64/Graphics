#pragma once
#include "../includes/glad.h"
#include <GLFW/glfw3.h>
#include<iostream>
#include <fstream>
#include <sstream>
#include <string>
namespace opg
{

	class Shader
	{
		private:
			const char* vShaderPath; 
			const char* fShaderPath;
			const char* fShaderSource;
			const char* vShaderSource;
			unsigned int vertexShader;
			unsigned int fragmentShader;
			unsigned int* shaderProgram;
			void createShaders();
		public:
			Shader(const char* vShaderPath, const char *fShaderPath, unsigned int* shaderProgram);
			~Shader();
			

			
	};

	std::string loadShaderSource(const char* filePath);
	GLFWwindow* glfwConfiguration(int a, int b);
};