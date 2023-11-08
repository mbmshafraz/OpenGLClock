//
//  VertexArray.hpp
//  HelloOpenGL
//
//  Created by Mohamed Shafraz on 2021-06-22.
//

#ifndef VertexArray_hpp
#define VertexArray_hpp

#include <stdio.h>
#include "vertexbuffer.hpp"
#include "vertexbufferlayout.hpp"


class VertexArray {
private:
    unsigned int mRendererID;
public:
    VertexArray();
    ~VertexArray();
    
    void addBuffer(const VertexBuffer& buffer, VertexBufferLayout& layout);
    void bind() const;
    void unbind() const;
};

#endif /* VertexArray_hpp */
