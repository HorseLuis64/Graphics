#include <openConf.h>
#include <texLoader.h>
#include <cmath>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

std::string actPath = std::filesystem::current_path(); 

std::string vPath = actPath + "../src/vertexShader.vs";
const char* vertexShaderCode = "/home/horseluis/HorseDev/Graphics/src/vertexShader.vs";
//const char* vertexShaderSource = vertexShaderCode.c_str();

std::string fPath = actPath + "../src/fragmentShader.fs";
const char* fragmentShaderCode = "/home/horseluis/HorseDev/Graphics/src/fragmentShader.fs";
//const char* fragmentShaderSource = fragmentShaderCode.c_str();
int counter = 0;

float vertices[] =
{
    -0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,    0.2f, 0.0f,  0.0f, 0.0f,
     0.5f,  0.5f, 0.0f,   0.0f, 1.0f, 0.0f,    0.8f, 0.0f,  1.0f, 0.0f,
     0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f,    0.8f, 1.0f,  1.0f, 1.0f,
    -0.5f, -0.5f, 0.0f,   0.4f, 0.5f, 1.0f,    0.2f, 1.0f,  0.0f, 1.0f
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

bool now = true;
float speed = 0.01f;
bool movePress;
glm::vec2 dir = glm::vec2(0.0f,0.0f);
void takeInput(GLFWwindow* window, int loc, glm::mat4 &trans)
{
    dir = glm::vec2(0.0f,0.0f);
    movePress = false;
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
    {
        glfwSetWindowShouldClose(window, true);
    }
    if(glfwGetKey(window, GLFW_KEY_X) == GLFW_PRESS)
    {
        glUniform1f(loc, 0.0f);
        if(now)
        {
            counter++;
        }
        now = false;
    }
    else
    {
        now = true;
        glUniform1f(loc, 1.0f);
    }
    if(glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS)
    {
        dir.y = 1;   
        movePress = true;
    }
    if(glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS)
    {
        dir.y = -1;
        movePress = true;
    }
    
    if(glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS)
    {
        dir.x = -1;
        movePress = true;
    }
    
    if(glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS)
    {
        dir.x = 1;
        movePress = true;
    }
    

    if(movePress == false)
    {
        dir = glm::vec2(0.0f,0.0f);
        //trans = glm::mat4(1.0f);
    }
}


int main()
{
    
    std::cout<<"PATHH == "<<std::filesystem::current_path()<<std::endl;
    GLFWwindow* window = opg::glfwConfiguration(800, 800);
    unsigned int shaderProgram;
    
    opg::Shader shader(vertexShaderCode, fragmentShaderCode);
   
    shader.createShaderProgram(shaderProgram);
    
    
    //generating the texture
    unsigned int texture;
    glGenTextures(1, &texture);
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, texture);


    //texture configuration
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    
    //method of determination of texel for magnifiyinh og minifyng
    //(sacaling up or down the image)
    //glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    //glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

    //configurarition of mipmaps behaviour
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_NEAREST);   
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);


    int width, height, nrChannels;
    
    unsigned char* data = img::loadImage("/home/horseluis/HorseDev/Graphics/assets/omni.jpeg", width, height, nrChannels);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
    glGenerateMipmap(GL_TEXTURE_2D); //i know what does, but, you know

    stbi_image_free(data);
    
    unsigned int texture2; 
    glGenTextures(1, &texture2);
    glActiveTexture(GL_TEXTURE1);
    glBindTexture(GL_TEXTURE_2D, texture2);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    
    width = 0;
    height = 0;
    nrChannels = 0;
    data = img::loadImage("/home/horseluis/HorseDev/Graphics/assets/man.jpeg", width, height, nrChannels);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
    glGenerateMipmap(GL_TEXTURE_2D);

    stbi_image_free(data);
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
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 10 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE,  10 * sizeof(float), (void*)( 3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 10 * sizeof(float), (void*)(6 * sizeof(float)));
    glEnableVertexAttribArray(2);

    glVertexAttribPointer(3,2, GL_FLOAT, GL_FALSE, 10 * sizeof(float), (void*)(8 * sizeof(float)));
    glEnableVertexAttribArray(3);   

    glBindVertexArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    

    
    
    glUseProgram(shaderProgram);
    //setting the unit of each sampler2d (glactive0 / 1), 2, 3...
    glUniform1i(glGetUniformLocation(shader.Id(), "texture1"), 0);
    glUniform1i(glGetUniformLocation(shader.Id(), "texture2"), 1);
    //glBindTexture(GL_TEXTURE_2D, texture);
    glBindVertexArray(VAO);
    
    
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, texture);
    glActiveTexture(GL_TEXTURE1);
    glBindTexture(GL_TEXTURE_2D, texture2);
    //this mf tells how to draw the shapes, if to
    //do it as a wireframe (lines), or fill the mesh
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    unsigned int loc = glGetUniformLocation(shader.Id(), "trans");

    //creating vector
    glm::vec4 vec(1.0f, 0.0f,0.0f,1.0f);
    //an identity matrix ( the diagonal )
    glm::mat4 trans = glm::mat4(1.0f);
    
    //vec = trans * vec;

    //trans = glm::scale(trans, glm::vec3(0.5f,0.5f,0.5f));
    std::cout<<vec.x<< vec.y<<vec.z;
    // Main render loop
    float angle = 0.0f;

    //model matrix will be use to aply transformations to the global world
    //space
    glm::mat4 model = glm::mat4(1.0f);
    model = glm::rotate(model, glm::radians(-55.0f), glm::vec3(1.0f,0.0f,0.0f));

    //view matrix (the camera matrix), we move the space so the camera
    //can look it
    glm::mat4 view = glm::mat4(1.0f);
    view = glm::translate(view, glm::vec3(0.0f, 0.0f,-1.0f));

    //projection matrix, move the coords to a w component
    //makes 3d
    glm::mat4 projection = glm::mat4(1.0f);
    projection = glm::perspective(glm::radians(45.0f), 800.0f / 800.0f, 0.1f, 100.0f);


    int viewLoc = glGetUniformLocation(shader.Id(), "view");
    int modelLoc = glGetUniformLocation(shader.Id(), "model");
    int projLoc = glGetUniformLocation(shader.Id(), "projection");

    glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
    glUniformMatrix4fv(viewLoc, 1, GL_FALSE, &view[0][0]);
    glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(projection));

    while (!glfwWindowShouldClose(window))
    {
        //---------------INPUT------------
        takeInput(window, loc, trans);

        //-------------TODO: PHYSICS-----------
        

        //----------------RENDERING----------
        glClearColor(0.12f, 0.45f, 0.7f, 0.9f);
        glClear(GL_COLOR_BUFFER_BIT);
        
        //trans = glm::mat4(1.0f);
        
        trans = glm::translate(trans, glm::vec3(dir.x,dir.y,0.0f) * speed);
        //trans = glm::rotate(trans, (float)glfwGetTime(), glm::vec3(0.0f,0.0f,1.0f));
       
        glUniformMatrix4fv(glGetUniformLocation(shader.Id(), "transform"), 1, GL_FALSE, glm::value_ptr(trans));  

        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT,  0);

        /*THIS MAKES ANOTHER IMAGE
        (dk why)
        trans = glm::mat4(1.0f);
        trans = glm::translate(trans, glm::vec3(-0.5f,0.5f,0.0f));
        glUniformMatrix4fv(glGetUniformLocation(shaderProgram, "transform"), 1, GL_FALSE, &trans[0][0]);
        */
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
        
        if(angle >= 90.0f)
        {
            angle = 0.0f;
        }

        angle++;
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