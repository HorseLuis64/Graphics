#include "openConf.h"
#include "texLoader.h"
#include <cmath>

std::string actPath = std::filesystem::current_path(); 

std::string vPath = actPath + "../src/vertexShader.vs";
const char* vertexShaderCode = "/home/horseluis/HorseDev/Graphics/src/vertexShader.vs";
//const char* vertexShaderSource = vertexShaderCode.c_str();

std::string fPath = actPath + "../src/fragmentShader.fs";
const char* fragmentShaderCode = "/home/horseluis/HorseDev/Graphics/src/fragmentShader.fs";
//const char* fragmentShaderSource = fragmentShaderCode.c_str();

float vertices[] =
{
    -0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,    0.0f, 0.0f, 
     0.5f,  0.5f, 0.0f,   0.0f, 0.0f, 0.0f,    0.0f, 1.0f, 
     0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 0.0f,    1.0f, 1.0f,
    -0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 0.0f,    1.0f, 0.0f
};

float texCoord[] = 
{
    0.0f, 0.0f, 
    0.0f, 1.0f, 
    1.0f, 1.0f,
    1.0f, 0.0f
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
    std::cout<<"PATHH == "<<std::filesystem::current_path()<<std::endl;
    GLFWwindow* window = opg::glfwConfiguration(800, 800);
    unsigned int shaderProgram;
    
    opg::Shader shader(vertexShaderCode, fragmentShaderCode);
   
    shader.createShaderProgram(shaderProgram);
    
 
    

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
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE,  8 * sizeof(float), (void*)( 3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
    glEnableVertexAttribArray(2);

    glBindVertexArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    


    //generating the texture
    unsigned int texture;
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);


    //texture configuration
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    
    //method of determination of texel for magnifiyinh og minifyng
    //(sacaling up or down the image)
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);


    //configurarition of mipmaps behaviour
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_NEAREST);   
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);



    int width, height, nrChannels;
    unsigned char* data = img::loadImage("/home/horseluis/HorseDev/Graphics/assets/omni.jpeg", width, height, nrChannels);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
    glGenerateMipmap(GL_TEXTURE_2D); //i know what does, but, you know

    stbi_image_free(data);

    int xLocation = glGetUniformLocation(shaderProgram, "xValue");
    
    glUseProgram(shaderProgram);
    glBindTexture(GL_TEXTURE_2D, texture);
    glBindVertexArray(VAO);
    
    glUniform1f(xLocation, 0.0f);

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