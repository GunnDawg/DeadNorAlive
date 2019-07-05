#VERTEX SHADER
#version 330 core

layout(location = 0) in vec4 position;
layout(location = 1) in vec3 color;

out vec3 ourColor;

void main()
{
	gl_Position = position;
	ourColor = color;
};

#FRAGMENT SHADER
#version 330 core

out vec4 FragColor;
in vec3 ourColor;

layout(location = 0) out vec4 color;

void main()
{
	FragColor = vec4(ourColor, 1.0f);
};