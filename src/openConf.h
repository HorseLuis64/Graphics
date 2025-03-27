#ifndef SHADER_H
#define SHADER_H

#include "../includes/glad.h"
#include <GLFW/glfw3.h>
#include<iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <filesystem>
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
			unsigned int shaderProgram;
			void createShaders();
		public:
			Shader(const char* vShaderPat, const char *fShaderPat);
			~Shader();
			
			void createShaderProgram(unsigned int &shaderProgram);
			unsigned int getVertex();
			unsigned int getFragment();
				
	};

	std::string loadShaderSource(const char* filePath);
	GLFWwindow* glfwConfiguration(int a, int b);
};

#endif