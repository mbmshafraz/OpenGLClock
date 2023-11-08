//
//  Shader.hpp
//  HelloOpenGL
//
//  Created by Mohamed Shafraz on 2021-06-23.
//

#ifndef Shader_hpp
#define Shader_hpp

#include <stdio.h>
#include <string>
#include <GL/glew.h>
#include <unordered_map>
#include <glm/glm.hpp>

struct ShaderProgramSource {
    std::string vertexSource;
    std::string fragmetnSource;
};

class Shader {
private:
    std::string mFilePath;
    unsigned int mRendererID;
    std::unordered_map<std::string, int> mUniformLocationCache;
    
public:
    Shader(const std::string& filepath);
    ~Shader();
    
    void bind() const;
    void unbind() const;
    
    // Set uniforms
    void setUniform4f(const std::string& name, float v0, float v1, float v2, float v3);
    void setUniform1f(const std::string& name, float value);
    void setUniformMat4f(const std::string& name, const glm::mat4& matrix);

private:
    GLuint compileShader( GLuint type, const std::string& source);
    GLuint createShader(const std::string& vatexShader, const std::string& fragmentShader);
    unsigned int getUniformLocation(const std::string& name);
    void printShaderLog(GLuint shader);
    ShaderProgramSource parseShader(const std::string& filepath);
};

#endif /* Shader_hpp */
