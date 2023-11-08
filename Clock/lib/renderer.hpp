//
//  Renderer.hpp
//  HelloOpenGL
//
//  Created by Mohamed Shafraz on 2021-06-22.
//

#ifndef Renderer_hpp
#define Renderer_hpp

#include <stdio.h>
#include "vertexarray.hpp"
#include "indexbuffer.hpp"
#include "shader.hpp"

class Renderer {
public:
    void clear() const;
    void clear(float r, float g, float b, float a) const;
    void draw(const VertexArray& va, const IndexBuffer& ib, const Shader& shader) const;
};

#endif /* Renderer_hpp */
