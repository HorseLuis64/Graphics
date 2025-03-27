#version 330 core
out vec4 FragColor;

in vec4 vertexColor;
in vec2 texCoord;
//uniform vec4 sexyColor;

//type of data for texture objects
//uniform sampler2D Texture;
void main()
{
    //built int function that made all for us
    FragColor = vertexColor;
}

