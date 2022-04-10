#shader vertex
#version 450 core

layout(location = 0) in vec3 position;

void main()
{
	gl_Position = position;
}

#shader fragment
#version 450 core

void main()
{
	color = vec4(1.0, 0.0, 0.0, 1.0)
}
