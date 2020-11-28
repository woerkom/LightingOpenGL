#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "Texture.h"
#include "Shader.h"
#include <map>

class sprite_renderer
{
public:
    sprite_renderer(std::map<std::string, Shader> &shaders);
    ~sprite_renderer();
    void drawSprite(/*Texture2D& texture, glm::vec2 position, glm::vec2 size = glm::vec2(10.0f, 10.0f), float rotate = 0.0f, glm::vec3 color = glm::vec3(1.0f)*/);
private:
    std::map<std::string, Shader>       *shaders;
    unsigned int quadVAO, lightVAO;
    void initRenderData();
};

