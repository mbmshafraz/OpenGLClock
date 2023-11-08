//
//  VertexBufferLayout.cpp
//  HelloOpenGL
//
//  Created by Mohamed Shafraz on 2021-06-22.
//

#include "vertexbufferlayout.hpp"

template<typename T>
void push(unsigned int count) {
//    static_assert(false);
}

template<>
void VertexBufferLayout::push<float>(unsigned int count) {
    mElements.push_back({GL_FLOAT, count,GL_FALSE});
    mStride += count * VertexBufferElement::getSizeOfType(GL_FLOAT);
}

template<>
void VertexBufferLayout::push<unsigned int>(unsigned int count) {
    mElements.push_back({GL_UNSIGNED_INT, count,GL_FALSE});
    mStride += count * VertexBufferElement::getSizeOfType(GL_UNSIGNED_INT);
}

template<>
void VertexBufferLayout::push<unsigned char>(unsigned int count) {
    mElements.push_back({GL_UNSIGNED_BYTE, count, GL_TRUE});
    mStride += count * VertexBufferElement::getSizeOfType(GL_UNSIGNED_BYTE);
}

