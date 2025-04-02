#ifndef IMAGE_LOADER
#define IMAGE_LOADER

#include "../includes/stb_image.h"

namespace img
{
    unsigned char* loadImage(const char* name, int &width, int &height, int &nrChannels);

    void freeData();
}

#endif