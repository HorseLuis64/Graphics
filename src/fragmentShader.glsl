#version 330 core
out vec4 FragColor;

in vec4 vertexColor;
//uniform vec4 sexyColor;
in vec2 texCoord;

uniform sampler2D lTexture;
void main()
{
    
    FragColor = texture(lTexture, texCoord);
}

