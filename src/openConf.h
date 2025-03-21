#pragma once
#include "../includes/glad.h"
#include <GLFW/glfw3.h>
#include<iostream>
#include <fstream>
#include <sstream>
#include <string>
namespace opg
{
	std::string loadShaderSource(const char* filePath);
	GLFWwindow* glfwConfiguration(int a, int b);
};