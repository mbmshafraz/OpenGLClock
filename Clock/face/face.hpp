//
//  face.hpp
//  Clock
//
//  Created by Mohamed Shafraz on 2021-06-25.
//

#ifndef face_hpp
#define face_hpp

#include <stdio.h>

#include "vertexarray.hpp"
#include "vertexbuffer.hpp"
#include "vertexbufferlayout.hpp"
#include "indexbuffer.hpp"
#include "shader.hpp"

class Face {
private:
    
    // Dial
    float mDialPositions[6] = {
        0.10f,  0.02,
        0.00f,  0.00f,
        0.10f, -0.02f
    };
    
    unsigned int mDialIdices[3] = {0,1,2};
    
    float mRadius;
    VertexArray mDialVA;
    VertexBufferLayout mDialLayout;
    Shader mDialShader = Shader("dial.glsl");
    IndexBuffer mDialIB = IndexBuffer(mDialIdices, 3);
    VertexBuffer mDialVB;

    Shader mBorderShader = Shader("border.glsl");
    GLuint mBorderVA[1];
    
public:
    Face(float mRadius);
    ~Face();
    void render();
};

#endif /* face_hpp */
