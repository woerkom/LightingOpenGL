#pragma once

#include <map>
#include "Texture.h"
#include "Shader.h"
class lighting_game
{
public:

    unsigned int Width, Height;
    unsigned int level;
    lighting_game(unsigned int width, unsigned int height);
    ~lighting_game();
    void Init();
    // game loop
    void ProcessInput(float dt, bool Keys[1024]);
    void Update(float dt);
    void Render();
private:
    std::map<std::string, Texture2D> m_textures;
    std::map<std::string, Shader> m_shaders;
};

