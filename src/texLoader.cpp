#define STB_IMAGE_IMPLEMENTATION
#include "texLoader.h"

namespace img
{
    unsigned char* loadImage(const char* fname, int &width, int &height, int &nrChannels)
    {
        return stbi_load(fname, &width, &height, &nrChannels, 0);        
        
    }

    void freeData()
    {
        
    }
}