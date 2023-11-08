//
//  IndexBuffer.cpp
//  HelloOpenGL
//
//  Created by Mohamed Shafraz on 2021-06-22.
//

#include "indexbuffer.hpp"
#include "util.hpp"


IndexBuffer::IndexBuffer(const GLuint* data, unsigned int count) : mCount(count) {
    GLCall(glGenBuffers(1, &mRendererID));
    GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mRendererID));
    GLCall(glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(GLuint), data, GL_STATIC_DRAW));
}

IndexBuffer::~IndexBuffer() {
    GLCall(glDeleteBuffers(1,&mRendererID));
}

void IndexBuffer::bind() const {
    GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mRendererID));
}

void IndexBuffer::unbind() const {
    GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0));
}
