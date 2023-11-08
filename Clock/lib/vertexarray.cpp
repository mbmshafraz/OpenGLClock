//
//  VertexArray.cpp
//  HelloOpenGL
//
//  Created by Mohamed Shafraz on 2021-06-22.
//

#include "vertexarray.hpp"
#include "util.hpp"

VertexArray::VertexArray() {
    GLCall(glGenVertexArrays(1,&mRendererID));
}

VertexArray::~VertexArray() {
    GLCall(glDeleteVertexArrays(1,&mRendererID));
}

void VertexArray::addBuffer(const VertexBuffer& buffer, VertexBufferLayout& layout) {
    bind();
    buffer.bind();
    const auto& elements = layout.getElements();
    
    unsigned long offset = 0;
    
    for (unsigned int i = 0; i < elements.size(); i++) {
        const auto& element = elements[i];
        GLCall(glEnableVertexAttribArray(i));
        GLCall(glVertexAttribPointer(i, element.count, element.type, element.normalized, layout.getStraide(),(const void*)offset));
        offset += element.count * VertexBufferElement::getSizeOfType(element.type);
    }
}

void VertexArray::bind() const {
    GLCall(glBindVertexArray(mRendererID));
}

void VertexArray::unbind() const {
    GLCall(glBindVertexArray(0));
}
