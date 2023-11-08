//
//  Shader.cpp
//  HelloOpenGL
//
//  Created by Mohamed Shafraz on 2021-06-23.
//

#include "shader.hpp"
#include "util.hpp"
#include <sstream>
#include <fstream>

using namespace std;

Shader::Shader(const std::string& filepath) : mFilePath(filepath), mRendererID(0) {
    ShaderProgramSource source = parseShader(filepath);
    mRendererID = createShader(source.vertexSource, source.fragmetnSource);
}

Shader::~Shader() {
    GLCall(glDeleteProgram(mRendererID));
}

void Shader::bind() const {
    GLCall(glUseProgram(mRendererID));
}

void Shader::unbind() const {
    GLCall(glUseProgram(0));
}

void Shader::setUniform4f(const std::string& name, float v0, float v1, float v2, float v3) {
    GLCall(glUniform4f(getUniformLocation(name), v0,v1,v2,v3));
}

void Shader::setUniform1f(const std::string &name, float value) {
    GLCall(glUniform1f(getUniformLocation(name),value));
}

void Shader::setUniformMat4f(const std::string& name, const glm::mat4& matrix) {
    GLCall(glUniformMatrix4fv(getUniformLocation(name),1,GL_FALSE, &matrix[0][0]));
}

unsigned int Shader::getUniformLocation(const std::string &name) {
    if (mUniformLocationCache.find(name) != mUniformLocationCache.end()) {
        return mUniformLocationCache[name];
    }
    
    GLCall(int location = glGetUniformLocation(mRendererID, name.c_str()));
        
    if (-1 == location) {
        std::cout << "Warning: uniform '" << name << "' doesn't exist!" << std::endl;
    }
    
    mUniformLocationCache[name] = location;
    
    return location;
}

GLuint Shader::compileShader( GLuint type, const std::string& source) {
    unsigned int id = glCreateShader(type);
    const char* src = source.c_str();
    glShaderSource(id, 1, &src,  nullptr);
    glCompileShader(id);
    
    int result;
    glGetShaderiv(id, GL_COMPILE_STATUS, &result);
    
    if (GL_FALSE == result) {
        int length;
        glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
        char* message = (char*)alloca(length *  sizeof(char));
        glGetShaderInfoLog(id, length, &length, message);
        std::cout << "Faild to compile"
                   << (type == GL_VERTEX_SHADER ? "vertex" : "Fragmet")
                   << "shader!" << std::endl;
        std::cout << message << std::endl;
        printShaderLog(id);
        glDeleteShader(id);
        return 0;
    }
    
    return id;
}

GLuint Shader::createShader(const std::string& vatexShader, const std::string& fragmentShader) {
    GLCall(unsigned int program = glCreateProgram());
    unsigned int vs = compileShader(GL_VERTEX_SHADER, vatexShader);
    unsigned int fs = compileShader(GL_FRAGMENT_SHADER, fragmentShader);
    
    GLCall(glAttachShader(program, vs));
    GLCall(glAttachShader(program, fs));
    GLCall(glLinkProgram(program));
    GLCall(glValidateProgram(program));
        
    GLCall(glDeleteShader(vs));
    GLCall(glDeleteShader(fs));
    
    return program;
}

void Shader::printShaderLog(GLuint shader) {
    int len = 0;
    int chWrittn = 0;
    char *log;
    glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &len);

    if (len > 0) {
        log = (char *)malloc(len);
        glGetShaderInfoLog(shader, len, &chWrittn, log);
        cout << "Shader Info Log: " << log << endl;
        free(log);
    }
}

ShaderProgramSource Shader::parseShader(const std::string& filepath) {
    std::ifstream stream(filepath);
    
    enum class ShaderTyp {
        NONE = -1, VERTEX = 0, FRAGMENT = 1
    };
    
    std::string line;
    std::stringstream ss[2];
    ShaderTyp type = ShaderTyp::NONE;
    
    while (getline(stream,line)) {
        if(line.find("#shader") != std::string::npos) {
            if (line.find("vertex") != std::string::npos) {
                type = ShaderTyp::VERTEX;
            } else if(line.find("fragment") != std::string::npos) {
                type = ShaderTyp::FRAGMENT;
            }
        } else {
            ss[(int)type] << line << '\n';
        }
    }
    
    return {ss[0].str(), ss[1].str()};
}

