//
//  face.cpp
//  Clock
//
//  Created by Mohamed Shafraz on 2021-06-25.
//

#include "face.hpp"
#include "util.hpp"

Face::Face(float radius)
    : mRadius(radius), mDialVB(mDialPositions, 6*sizeof(float))
{
    mDialShader.bind();
    mDialLayout.push<float>(2);
    mDialVA.addBuffer(mDialVB, mDialLayout);
    
    mDialVA.unbind();
    mDialVB.unbind();
    mDialIB.unbind();
    mDialShader.unbind();
    
    mBorderShader.bind();
    glGenVertexArrays(1, mBorderVA);
    glBindVertexArray(mBorderVA[0]);
}

Face::~Face() {
    mDialVA.unbind();
    mDialShader.unbind();
    mDialIB.unbind();
    mDialVB.unbind();
    
    mBorderShader.unbind();
};

void Face::render() {
    
    for (int i = 0; i < 12 ; i++) {
        mDialShader.bind();
        mDialShader.setUniform1f("u_Dial", i);
        mDialShader.setUniform1f("u_R", mRadius);
        mDialVA.bind();
        mDialIB.bind();
        
        GLCall(glDrawElements(GL_TRIANGLES, mDialIB.getCount(), GL_UNSIGNED_INT, nullptr));
    }

    int count = 1000;
    for (int i = 0; i < count; i++) {
        mBorderShader.bind();
        mBorderShader.setUniform1f("u_Count", count);
        mBorderShader.setUniform1f("u_R", mRadius + 0.15);
        mBorderShader.setUniform1f("u_Point", i);
        glPointSize(6.0f);
        GLCall(glDrawArrays(GL_POINTS, 0, 1));
    }
}
