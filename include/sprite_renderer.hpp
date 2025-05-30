#ifndef SPRITE_RENDERER_HPP
#define SPRITE_RENDERER_HPP

#include "shader.hpp"
#include "texture.hpp"
#include <glm/glm.hpp>

class SpriteRenderer
{
public:
    SpriteRenderer(const Shader &shader);
    ~SpriteRenderer();

    void drawSprite(const Texture2D &texture, glm::vec2 position, 
                    glm::vec2 size = glm::vec2(10.0f, 10.0f), float rotate = 0.0f,
                    glm::vec3 color = glm::vec3(1.0f));
private:
    Shader shader_;
    // NOTE: all sprites share the same data (rn) so 1 VAO
    unsigned int quadVAO_;

    void initRenderData();
};
#endif
