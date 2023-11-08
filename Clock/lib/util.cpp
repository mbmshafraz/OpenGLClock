//
//  util.cpp
//  GLFW OpenGL
//
//  Created by Mohamed Shafraz on 2021-06-17.
//

#include "util.hpp"
#include <fstream>
#include <string>
#include <sstream>


using namespace std;

void GLClearError() {
    while (glGetError() != GL_NO_ERROR);
}

bool GLLogCall() {
    while (GLenum error = glGetError()) {
        std::cout << "[OpenGL Error] ( " << std::hex << error << ")" << std::endl;
        return false;
    }
    return true;
}
