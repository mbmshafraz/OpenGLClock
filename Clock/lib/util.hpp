//
//  util.hpp
//  GLFW OpenGL
//
//  Created by Mohamed Shafraz on 2021-06-17.
//

#ifndef util_hpp
#define util_hpp

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>


#define GLCall(x) GLClearError();x;assert(GLLogCall())

void GLClearError();
bool GLLogCall();

#endif /* util_hpp */
