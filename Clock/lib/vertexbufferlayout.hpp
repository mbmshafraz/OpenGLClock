//
//  VertexBufferLayout.hpp
//  HelloOpenGL
//
//  Created by Mohamed Shafraz on 2021-06-22.
//

#ifndef VertexBufferLayout_hpp
#define VertexBufferLayout_hpp

#include <stdio.h>
#include <vector>
#include <GL/glew.h>

struct VertexBufferElement {
    unsigned int type;
    unsigned int count;
    unsigned char normalized;
    
    static unsigned int getSizeOfType(unsigned int type) {
        switch (type) {
            case GL_FLOAT:           return 4;
            case GL_UNSIGNED_INT:   return 4;
            case GL_UNSIGNED_BYTE:  return 1;
        }
        assert(false);
        return 0;
    }
};

class VertexBufferLayout{
private:
    std::vector<VertexBufferElement> mElements;
    unsigned int mStride;
public:
    VertexBufferLayout():mStride(0){};
    
    template<typename T>
    void push(unsigned int count);
    
    template<>
    void push<float>(unsigned int count);

    template<>
    void push<unsigned int>(unsigned int count);
    
    template<>
    void push<unsigned char>(unsigned int count);
    
    inline const std::vector<VertexBufferElement> getElements() const& { return mElements;}
    inline unsigned int getStraide() const { return mStride; }
};

#endif /* VertexBufferLayout_hpp */
