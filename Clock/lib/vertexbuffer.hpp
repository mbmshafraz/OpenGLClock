//
//  VertexBuffer.hpp
//  HelloOpenGL
//
//  Created by Mohamed Shafraz on 2021-06-22.
//

#ifndef VertexBuffer_hpp
#define VertexBuffer_hpp

#include <stdio.h>
#include <GL/glew.h>

class VertexBuffer {
private:
    unsigned int mRendererID;
public:
    VertexBuffer(const void* data, unsigned int size);
    VertexBuffer(unsigned size);
    ~VertexBuffer();
    
    void update(unsigned size, GLvoid * data) const;
    void bind() const;
    void unbind() const;
};

#endif /* VertexBuffer_hpp */
