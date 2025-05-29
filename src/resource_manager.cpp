#include <glad/glad.h>

#include "resource_manager.hpp"
#include <stb_image.h>

#include <iostream>
#include <fstream>
#include <sstream>

// instantiate static variables
std::map<std::string, Texture2D> ResourceManager::textures_;
std::map<std::string, Shader> ResourceManager::shaders_;

Shader ResourceManager::loadShader(const char* vShaderFile, const char* fShaderFile, const char*  gShaderFile, std::string name) 
{
    shaders_[name] = loadShaderFromFile(vShaderFile, fShaderFile, gShaderFile);
    return shaders_[name];
}

Shader ResourceManager::getShader(std::string name)
{
    return shaders_[name];
}

Texture2D ResourceManager::loadTexture(const char* file, bool alpha, std::string name)
{
    textures_[name] = loadTextureFromFile(file, alpha);
    return textures_[name];
}

Texture2D ResourceManager::getTexture(std::string name)
{
    return textures_[name];
}

void ResourceManager::clear()
{
    // (properly) delete all shaders
    for (auto iter : shaders_)
        glDeleteProgram(iter.second.ID_);
    // (properly) delete all textures
    for (auto iter : textures_)
        glDeleteTextures(1, &iter.second.ID_);
}

Shader ResourceManager::loadShaderFromFile(const char* vShaderFile, const char* fShaderFile, const char* gShaderFile)
{
    // 1. retrieve the vertex/fragment source code from filePath
    std::string vertexCode;
    std::string fragmentCode;
    std::string geometryCode;
    try
    {
        // open files
        std::ifstream vertexShaderFile(vShaderFile);
        std::ifstream fragmentShaderFile(fShaderFile);
        std::stringstream vShaderStream, fShaderStream;
        // read file's buffer contents into streams
        vShaderStream << vertexShaderFile.rdbuf();
        fShaderStream << fragmentShaderFile.rdbuf();
        // close file handlers
        vertexShaderFile.close();
        fragmentShaderFile.close();
        // convert stream into string
        vertexCode = vShaderStream.str();
        fragmentCode = fShaderStream.str();
        // if geometry shader path is present, also load a geometry shader
        if (gShaderFile != nullptr)
        {
            std::ifstream geometryShaderFile(gShaderFile);
            std::stringstream gShaderStream;
            gShaderStream << geometryShaderFile.rdbuf();
            geometryShaderFile.close();
            geometryCode = gShaderStream.str();
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << "ERROR::SHADER: Failed to read shader files" << std::endl;
    }

    const char *vShaderCode = vertexCode.c_str();
    const char *fShaderCode = fragmentCode.c_str();
    const char *gShaderCode = geometryCode.c_str();
    // 2. now create shader object from source code
    Shader shader;
    shader.compile(vShaderCode, fShaderCode, gShaderFile != nullptr ? gShaderCode : nullptr);
    return shader;
}

Texture2D ResourceManager::loadTextureFromFile(const char* file, bool alpha)
{
    // create texture object
    Texture2D texture;
    if (alpha)
    {
        texture.internalFormat_ = GL_RGBA;
        texture.imageFormat_ = GL_RGBA;
    }
    // load image
    int width, height, nrChannels;
    unsigned char* data = stbi_load(file, &width, &height, &nrChannels, 0);
    // generate texture
    texture.generate(width, height, data);
    // free image data
    stbi_image_free(data);
    return texture;
}
