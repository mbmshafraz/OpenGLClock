//
//  Renderer.cpp
//  HelloOpenGL
//
//  Created by Mohamed Shafraz on 2021-06-22.
//

#include "renderer.hpp"
#include "util.hpp"

void Renderer::clear() const {
    glClear(GL_COLOR_BUFFER_BIT);
}

void Renderer::clear(float r, float g, float b, float a) const {
    clear();
    GLCall(glClearColor(r, g, b, a));
}

void Renderer::draw(const VertexArray &va, const IndexBuffer &ib, const Shader& shader) const {
    shader.bind();
    va.bind();
    ib.bind();
    
    GLCall(glDrawElements(GL_TRIANGLES, ib.getCount(), GL_UNSIGNED_INT, nullptr));
}
