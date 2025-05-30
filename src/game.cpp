#include "game.hpp"
#include "resource_manager.hpp"
#include "sprite_renderer.hpp"

// Game-related State data
SpriteRenderer  *Renderer;

Game::Game(unsigned int width, unsigned int height) 
    : state_(GameState::GAME_ACTIVE), keys_(), width_(width), height_(height)
{ 

}

Game::~Game()
{
    delete Renderer;
}

void Game::init()
{
    // load shaders
    ResourceManager::loadShader("../shaders/vertex.vs", "../shaders/fragment.fs", nullptr, "sprite");
    // configure shaders
    glm::mat4 projection = glm::ortho(0.0f, static_cast<float>(this->width_), 
        static_cast<float>(this->height_), 0.0f, -1.0f, 1.0f);
    ResourceManager::getShader("sprite").use().setInteger("image", 0);
    ResourceManager::getShader("sprite").setMatrix4("projection", projection);
    // set render-specific controls
    Renderer = new SpriteRenderer(ResourceManager::getShader("sprite"));
    // load textures
    ResourceManager::loadTexture("../awesomeface.png", true, "face");
}

void Game::update(float dt)
{
    
}

void Game::processInput(float dt)
{
   
}

void Game::render()
{
    Renderer->drawSprite(ResourceManager::getTexture("face"), glm::vec2(200.0f, 200.0f), glm::vec2(300.0f, 400.0f), 45.0f, glm::vec3(0.0f, 1.0f, 0.0f));
}
