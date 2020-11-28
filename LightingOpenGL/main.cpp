#include "glfw_window.h"
#include "lighting_game.h"
#include <iostream>

const unsigned int SCREEN_WIDTH = 800;
const unsigned int SCREEN_HEIGHT = 600;


int main(void)
{
    glfw_window* display = new glfw_window();
    display->init(SCREEN_WIDTH, SCREEN_HEIGHT, "OpenGL Lighting");

    lighting_game* light_tutorial = new lighting_game(SCREEN_WIDTH, SCREEN_HEIGHT);
    light_tutorial->Init();

    // deltaTime variables
    float deltaTime = 0.0f;
    float lastFrame = 0.0f;
    while (!display->isClosed())
    {
        // per frame logic
        float currentFrame = glfwGetTime();
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;

        display->clear();

        display->events();

        light_tutorial->ProcessInput(deltaTime, display->get_keys());
        light_tutorial->Update(deltaTime);
        light_tutorial->Render();

        display->swapBuffers();

    }

    display->delete_window();
    return 0;
}