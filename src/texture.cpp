#include <glad/glad.h>

#include "texture.hpp"
#include <iostream>

Texture2D::Texture2D()
    : width_(0), height_(0), internalFormat_(GL_RGB), imageFormat_(GL_RGB), wrapS_(GL_REPEAT),
        wrapT_(GL_REPEAT), filterMin(GL_LINEAR), filterMax(GL_LINEAR)
{
    glGenTextures(1, &this->ID_);
}

void Texture2D::generate(unsigned int width, unsigned int height, unsigned char* data)
{
    this->width_ = width;
    this->height_ = height;
    // create texture
    glBindTexture(GL_TEXTURE_2D, this->ID_);
    glTexImage2D(GL_TEXTURE_2D, 0, this->internalFormat_, width, height, 0, this->imageFormat_, GL_UNSIGNED_BYTE, data);
    // set Texture wrap and filter modes
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, this->wrapS_);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, this->wrapT_);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, this->filterMin);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, this->filterMax);
    // unbind texture
    glBindTexture(GL_TEXTURE_2D, 0);
}

void Texture2D::bind() const
{
    glBindTexture(GL_TEXTURE_2D, this->ID_);
}