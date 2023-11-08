//
//  hand.hpp
//  Clock
//
//  Created by Mohamed Shafraz on 2021-06-24.
//

#ifndef hand_hpp
#define hand_hpp

#include <stdio.h>
#include "vertexarray.hpp"
#include "vertexbuffer.hpp"
#include "vertexbufferlayout.hpp"
#include "indexbuffer.hpp"
#include "shader.hpp"

class Hand {
private:
        
    float mPositions[8] = {
        0.00f, 1.00f,
       -0.04f, 0.10f,
        0.04f, 0.10f,
        0.00f, 0.00f
    };
    
    unsigned int mIdices[6] = {0,1,2,1,4,2};
    
    float mHeight;
    VertexArray mVA;
    VertexBufferLayout mLayout;
    Shader mShader = Shader("hand.glsl");
    IndexBuffer mIB = IndexBuffer(mIdices, 6);
    VertexBuffer mVB;
    float mR;
    float mG;
    float mB;
    float mA;
    
public:
    Hand(float height, float r, float g, float b, float a);
    ~Hand();
    void render(float value);
};

#endif /* hand_hpp */
