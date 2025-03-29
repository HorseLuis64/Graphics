#include "openConf.h"
#include <cmath>

#define STB_IMAGE_IMPLEMENTATION
#include "../includes/stb_image.h"
const char* vertexShaderCode = "/home/horseluis/HorseDev/fixthis/Graphics/src/vertexShader.glsl";
//const char* vertexShaderSource = vertexShaderCode.c_str();

const char* fragmentShaderCode = "/home/horseluis/HorseDev/fixthis/Graphics/src/fragmentShader.glsl";
//const char* fragmentShaderSource = fragmentShaderCode.c_str();

float vertices[] =
{
    -0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,
     0.5f,  0.5f, 0.0f,   0.0f, 0.0f, 0.0f,
     0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 0.0f,
    -0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 0.0f
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


int main()
{
    GLFWwindow* window = opg::glfwConfiguration(800, 800);
    unsigned int shaderProgram;
    opg::Shader shader(vertexShaderCode, fragmentShaderCode);
   
    shader.createShaderProgram(shaderProgram);
    
    unsigned int texture;
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_NEAREST);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    int width, height, nrChannels;

    unsigned char* data = stbi_load("/home/horseluis/HorseDev/fixthis/Graphics/assets/omni.jpeg", &width, &height, &nrChannels, 0);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
    glGenerateMipmap(GL_TEXTURE_2D);


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
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE,  6 * sizeof(float), (void*)( 3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    
    glBindVertexArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    

    float time; 
    float green; 
    int vertexColorLocation; 


    glUseProgram(shaderProgram);
    glBindVertexArray(VAO);


    //this mf tells how to draw the shapes, if to
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

        time = glfwGetTime();
        green = (sin(time) / 2.0f) + 0.5f;

        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT,  0);





        //this is to find an uniform variable
       // vertexColorLocation = glGetUniformLocation(shaderProgram, "sexyColor");
       // glUniform4f(vertexColorLocation, 0.0f, green, 0.0f, 1.0f);
       // glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT,  0);
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