#version 330 core
layout(location = 0) in vec3 aPos;
layout(location = 1) in vec3 aColor;
layout(location = 2) in vec2 texPos;
layout(location = 3) in vec2 texPos1;
out vec4 vertexColor;
out vec2 texCoord;
out vec2 texCoord1;

uniform mat4 transform;
void main()
{
    gl_Position = transform * vec4(aPos, 1.0);
    vertexColor = vec4(aColor, 1.0);
    texCoord = texPos;
    texCoord1 = texPos1;
}