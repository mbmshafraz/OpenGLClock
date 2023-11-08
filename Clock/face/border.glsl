#shader vertex

#version 410 core

layout(location = 0) in vec4 position;

uniform float u_Point;
uniform float u_Count;
uniform float u_R;

void main(void)
{
    vec3 pos = vec3(0.0,0.0,1.0);
    float t =  2*3.14159*u_Point/u_Count;
    float si = sin(t);
    float co = cos(t);

    //OpenGL Handles matrix column vise
    //In this matrix rows should be read columns and columns as rows
    mat3 tt =  mat3(1.0,     0.0, 0.0,
                     0.0,     1.0, 0.0,
                    u_R*co, u_R*si, 1.0);


    vec3 translated = tt * pos;
    
    gl_Position = vec4(translated.xyz, 1.0);
}

#shader fragment

#version 410 core

out vec4 color;

void main(void)
{
    color = vec4(8.0/255.0, 135.0/255.0, 172.0/255.0, 1.0);
}

