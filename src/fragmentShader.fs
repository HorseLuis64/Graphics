#version 330 core
out vec4 FragColor;

in vec4 vertexColor;
in vec2 texCoord;
in vec2 texCoord1;
//uniform vec4 sexyColor;

//type of data for texture objects
uniform sampler2D texture1;
uniform sampler2D texture2;
uniform float trans;
void main()
{
    //built int function that made all for us
    FragColor = mix(texture(texture1, texCoord), texture(texture2, texCoord1), trans);
}

