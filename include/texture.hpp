#ifndef TEXTURE_HPP
#define TEXTURE_HPP

class Texture2D
{
public:
    // holds ID of the texture object, used for all texture operations to reference this texture
    unsigned int ID_;
    unsigned int width_, height_;

    unsigned int internalFormat_; // format of texture object
    unsigned int imageFormat_; // format of loaded image

    unsigned int wrapS_; // wrapping mode on s axis
    unsigned int wrapT_; // wrapping mode on t axis
    unsigned int filterMin; // filtering mode if texture pixels < screen pixels
    unsigned int filterMax; // filtering moe if texture pixels > screen pixels

    Texture2D();
    // Generates the texture from image data
    void generate(unsigned int width, unsigned int height, unsigned char* data);
    // binds the texture as the current active GL_TEXTURE_2D texture object
    void bind() const;
};
#endif