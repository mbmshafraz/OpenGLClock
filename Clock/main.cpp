//
//  main.cpp
//  Clock
//
//  Created by Mohamed Shafraz on 2021-06-24.
//

#ifdef __APPLE__
    #pragma clang diagnostic push
    #pragma clang diagnostic ignored "-Wdocumentation"
    #include <GL/glew.h>
    #include <GLFW/glfw3.h>
    #pragma clang diagnostic pop
    #define GLEW_STATIC
#else
    #include <GL/glew.h>
    #include <GLFW/glfw3.h>
#endif

#include <iostream>
#include <ctime>

#include "util.hpp"
#include "vertexbuffer.hpp"
#include "indexbuffer.hpp"
#include "vertexarray.hpp"
#include "vertexbufferlayout.hpp"
#include "shader.hpp"
#include "renderer.hpp"
#include "hand.hpp"
#include "face.hpp"

#include <thread>

using namespace std;

// Uncomment this to simulate
//#define SIMULATE

int main(int argc, const char * argv[]) {
    GLFWwindow* window;
    
#ifdef __APPLE__
    glewExperimental = GL_TRUE;
#endif
    
    if (!glfwInit()) { exit(EXIT_FAILURE); }
    
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif
    
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
    window = glfwCreateWindow(400, 400, "CSC2031", NULL, NULL);
    
    if (!window)
    {
        glfwTerminate();
        exit(EXIT_FAILURE);;
    }
    
    int actualScreenWidth, actualScreenHeight;
    glfwGetFramebufferSize(window, &actualScreenWidth, &actualScreenHeight);
    
    /* Make the window's context current */
    glfwMakeContextCurrent(window);
    glViewport(0,0,actualScreenWidth,actualScreenHeight);
    
    if (GLuint code = glewInit()) {
        cout << "GLEW Init Failed for reason: "  <<  glewGetErrorString(code)<< endl;
        exit(EXIT_FAILURE);
    }
    
    glfwSwapInterval(1);
    
    Hand minuteHand = Hand(0.45f, 8.0/255.0, 135.0/255.0, 172.0/255.0, 1.0f);
    Hand hourHand =  Hand(0.35f, 0.0f, 0.0f, 0.0f, 1.0f);
    Face clockFace = Face(0.5f);
        
    while (!glfwWindowShouldClose(window)) {
        
        glClearColor(1.0, 1.0, 1.0, 1.0);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        
        clockFace.render();
        
        time_t tt;
        time( &tt );
        tm TM = *localtime( &tt );
        
#ifdef SIMULATE
        hourHand.render(TM.tm_min*5);
        minuteHand.render(TM.tm_sec);
#else
        hourHand.render(TM.tm_hour*5);
        minuteHand.render(TM.tm_min);
#endif
        
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    
    glfwDestroyWindow(window);
    glfwTerminate();
    exit(EXIT_SUCCESS);
}
