#include "openConf.h"

std::string vertexShaderCode = opg::loadShaderSource("/home/horseluis/HorseDev/Graphics/src/vertexShader.glsl");
const char* vertexShaderSource = vertexShaderCode.c_str();

std::string fragmentShaderCode = opg::loadShaderSource("/home/horseluis/HorseDev/Graphics/src/fragmentShader.glsl");
const char* fragmentShaderSource = fragmentShaderCode.c_str();

float vertices[] =
{
    -0.5f, 0.5f, 0.0f,
    0.5f, 0.5f, 0.0f,
    0.5f, -0.5f, 0.0f,
    -0.5f, -0.5f, 0.0f
};

unsigned int indices[] = 
{
    0, 1, 3,
    1, 2, 3
};

void takeInput(GLFWwindow* window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
    {
        glfwSetWindowShouldClose(window, true);
    }
}

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

int main()
{
    GLFWwindow* window = opg::glfwConfiguration(800, 800);
    
    // Initializing and compiling the vertex shader
    unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);
    checkShaderCompilation(vertexShader);

    // Initializing and compiling the fragment shader
    unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);
    checkShaderCompilation(fragmentShader);

    // Creating and linking the shader program
    unsigned int shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);
    checkProgramLinking(shaderProgram);

    // Deleting the shaders as they are now linked into our program
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    // Setting up the vertex data and buffers
    unsigned int VBO, VAO, EBO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

    //1. bind Vertex Array Object
    glBindVertexArray(VAO);
    
    //2.copy our vertices array in a Vertex Buffer Object to Opengl use it
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    //3. copy our indices order to a Element Buffer Object of opengl
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), &indices, GL_STATIC_DRAW);
    //4.Then set the vertex attribute pointers (configure teh VAO)
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);


    glUseProgram(shaderProgram);
    glBindVertexArray(VAO);


    //this mf tells how to draw the shapes, if
    //do it as a wireframe (lines), or fill the mesh
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    // Main render loop
    while (!glfwWindowShouldClose(window))
    {
        //---------------INPUT------------
        takeInput(window);

        //-------------TODO: PHYSICS-----------


        //----------------RENDERING----------
        glClearColor(0.12f, 0.45f, 0.7f, 0.9f);
        glClear(GL_COLOR_BUFFER_BIT);

       
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT,  0);

        // ----------------OUTPUT-------------
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    //this is optional btw, since
    //glfwTerminate do it automatically
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteBuffers(1, &EBO);
    glDeleteProgram(shaderProgram);

    glfwTerminate();
    return 0;
}