//
//  IndexBuffer.hpp
//  HelloOpenGL
//
//  Created by Mohamed Shafraz on 2021-06-22.
//

#ifndef IndexBuffer_hpp
#define IndexBuffer_hpp

#include <stdio.h>
#include <GL/glew.h>

class IndexBuffer {
private:
    unsigned int mRendererID;
    unsigned int mCount;
public:
    IndexBuffer(const GLuint* data, unsigned int count);
    ~IndexBuffer();
    
    void bind() const;
    void unbind() const;
    
    inline unsigned int getCount() const { return mCount;}
};

#endif /* IndexBuffer_hpp */
