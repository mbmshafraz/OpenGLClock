//
//  hand.cpp
//  Clock
//
//  Created by Mohamed Shafraz on 2021-06-24.
//

#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "hand.hpp"
#include "util.hpp"
#include <cmath>

Hand::Hand(float height, float r, float g, float b, float a)
    : mHeight(height),mVB(6*sizeof(float)), mR(r), mG(g), mB(b), mA(a)
{
    mPositions[1] = height;
    mShader.bind();
    mShader.setUniform4f("u_Color", mR, mG, mB, mA);
    mVB.update(6*sizeof(float), mPositions);
    mLayout.push<float>(2);
    mVA.addBuffer(mVB, mLayout);
    
    mVA.unbind();
    mVB.unbind();
    mIB.unbind();
    mShader.unbind();
};

Hand::~Hand() {
    mVA.unbind();
    mShader.unbind();
    mIB.unbind();
    mVB.unbind();
};

void Hand::render(float value) {
    
    mShader.bind();
    mShader.setUniform4f("u_Color", mR, mG, mB, mA);
    mShader.setUniform1f("u_Pos", value);
    mVA.bind();
    mIB.bind();
    
    GLCall(glDrawElements(GL_TRIANGLES, mIB.getCount(), GL_UNSIGNED_INT, nullptr));
}

