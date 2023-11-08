#shader vertex

#version 410 core

layout(location = 0) in vec4 position;

uniform float u_Dial;
uniform float u_R;

void main(void)
{
    vec3 pos = vec3(position.xy,1.0);
    float t = -3.14159*u_Dial/6.0;
    float si = sin(t);
    float co = cos(t);
    
    //OpenGL Handles matrix column vise
    //In this matrix rows should be read columns and columns as rows
    //This is used for rotate the objet
    mat3 tm = mat3(co, si, 0.0,
                   -si, co, 0.0,
                   0.0,0.0,1.0);
    
    vec3 transformed = tm * pos;
    
    //OpenGL Handles matrix column vise
    //In this matrix rows should be read columns and columns as rows
    //This is used for move the objet
    mat3 tt =  mat3(1.0,     0.0, 0.0,
                     0.0,     1.0, 0.0,
                    u_R*co, u_R*si, 1.0);
    
    vec3 translated = tt * transformed;
    gl_Position = vec4(translated.xyz,1.0);
}

#shader fragment

#version 410 core

out vec4 color;

void main(void)
{
    color = vec4(1.0, 0.0, 0.0, 1.0);
}

