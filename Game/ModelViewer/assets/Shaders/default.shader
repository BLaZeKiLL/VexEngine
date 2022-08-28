#shader vertex
#version 450 core

layout(location = 0) in vec3 position;
layout(location = 1) in vec3 normal;
layout(location = 2) in vec2 uv;

out vec2 v_uv;
out vec3 v_normal;
out vec3 v_position;

uniform mat4 u_Model;
uniform mat4 u_View;
uniform mat4 u_Projection;

void main()
{
	gl_Position = u_Projection * u_View * u_Model * vec4(position, 1.0);
	v_uv = uv;
	v_normal = mat3(transpose(inverse(u_Model))) * normal; // matrix computation should be moved to CPU
	v_position = vec3(u_Model * vec4(position, 1.0));
}

#shader fragment
#version 450 core

in vec2 v_uv;
in vec3 v_normal;
in vec3 v_position;

out vec4 color;

uniform sampler2D u_Texture;

uniform vec3 u_LightPosition;
uniform vec3 u_LightColor;

uniform vec4 u_BaseColor;
uniform float u_AmbientStrength;
uniform float u_SpecularStrength;
uniform int u_SpecularShine;

uniform vec3 u_ViewPosition;

void main()
{
	// Base Color
	vec4 object = u_BaseColor * texture(u_Texture, v_uv);

	// Ambient Light
	vec3 ambient = u_AmbientStrength * u_LightColor;

	// Diffuse Light
	vec3 normal = normalize(v_normal);
	vec3 light_direction = normalize(u_LightPosition - v_position);
	vec3 diffuse = u_LightColor * max(dot(normal, light_direction), 0.0);

	// Specular Light
	vec3 view_direction = normalize(u_ViewPosition - v_position);
	vec3 reflect_direction = reflect(-light_direction, normal);
	vec3 specular = u_LightColor * u_SpecularStrength * pow(max(dot(view_direction, reflect_direction), 0.0), u_SpecularShine);

	color = vec4(ambient + diffuse + specular, 1.0) * object;
}
