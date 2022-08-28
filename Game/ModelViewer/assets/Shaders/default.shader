#shader vertex
#version 450 core

layout(location = 0) in vec4 position;
layout(location = 1) in vec2 uv;

out vec2 v_uv;

uniform mat4 u_MVP;

void main()
{
	gl_Position = u_MVP * position;
	v_uv = uv;
}

#shader fragment
#version 450 core

in vec2 v_uv;

out vec4 color;

uniform vec4 u_LightColor;
uniform vec4 u_ObjectColor;
uniform sampler2D u_Texture;

void main()
{
	color = u_LightColor * u_ObjectColor * texture(u_Texture, v_uv);
}
