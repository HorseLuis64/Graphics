#version 330 core
layout(location = 0) in vec3 aPos;
layout(location = 1) in vec3 aColor;
layout(location = 2) in vec2 texPos
out vec4 vertexColor;
out vec2 texCoord;
uniform float xValue;
void main()
{
    gl_Position = vec4(xValue + aPos.x, aPos.yz, 1.0);
    texCoord = texPos;
    vertexColor = vec4(aPos, 1.0);
}