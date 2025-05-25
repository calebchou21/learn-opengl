#ifndef SHADER_HPP
#define SHADER_HPP

#include <glad/glad.h>

#include <string>

class Shader
{
public:
    // the program ID
    unsigned int ID_;

    // constructor reads + builds the shader
    Shader(const char* vertexPath, const char* fragmentPath);
    // use/activate the shader
    void use();
    // utility uniform functions
    void setBool(const std::string &name, bool value) const;
    void setFloat(const std::string &name, float value) const;
    void setInt(const std::string &name, int value) const;

private:
    void checkCompileErrors(unsigned int shader, std::string type);
};
#endif
