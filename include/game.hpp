#ifndef GAME_HPP
#define GAME_HPP

enum class GameState {
    GAME_ACTIVE,
    GAME_MENU,
    GAME_WIN
}; 

class Game
{
public:
    GameState state_;
    bool keys_[1024];
    unsigned int width_, height_;

    Game(unsigned int width, unsigned int height);
    ~Game();

    // initialize game state (load all shaders/textures/etc.)
    void init();
    // game loop
    void processInput(float dt);
    void update(float dt);
    void render();
};
#endif