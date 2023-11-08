#shader vertex

#version 410 core

layout(location = 0) in vec3 position;

uniform float u_Pos;

void main(void)
{
    float angle = -u_Pos*3.14159/30.0;
    float si = sin(angle);
    float co = cos(angle);
    
    //OpenGL Handles matrix column vise
    //In this matrix rows should be read columns and columns as rows
    mat3 mat = mat3(
          co, si, 0.0,
          -si,co, 0.0,
        0.0, 0.0, 1.0
    );
    
    vec3 transfered = mat * position;
    
    gl_Position = vec4(transfered.xyz, 1.0);
}

#shader fragment

#version 410 core

out vec4 color;

uniform vec4 u_Color;

void main(void)
{
    color = u_Color;
}

