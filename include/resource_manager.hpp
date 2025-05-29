#ifndef RESOURCE_MANAGER_HPP
#define RESOURCE_MANAGER_HPP

#include "texture.hpp"
#include "shader.hpp"
#include <map>
#include <string>

class ResourceManager
{
public:
    // resource storage
    static std::map<std::string, Shader> shaders_;
    static std::map<std::string, Texture2D> textures_;
    // loads (and generates) a shader program from file loading vertex, fragment (and geometry) shader's source code. 
    // if gShaderFile is not nullptr, it also loads a geometry shader
    static Shader loadShader(const char* vShaderFile, const char* fShaderFile, const char*  gShaderFile, std::string name);
    // retrieves a stored pointer
    static Shader getShader(std::string name);
    // loads (and generates) a texture from a file
    static Texture2D loadTexture(const char* file, bool alpha, std::string name);
    // retrieves a stored texture
    static Texture2D getTexture(std::string name);
    // properly de-allocates all loaded resources
    static void clear();
private:
    // private constructor (stupid singleton pattern...)
    ResourceManager() {};
    // loads and generates a shader from a file
    static Shader loadShaderFromFile(const char* vShaderFile, const char* fShaderFile, const char* gShaderFile = nullptr);
    // loads a single texture from a file
    static Texture2D loadTextureFromFile(const char* file, bool alpha);
};
#endif
