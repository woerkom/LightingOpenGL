#include "lighting_game.h"
#include "sprite_renderer.h"

/*El objetivo de esta clase es abstraer toda la lógica del tutorial dentro de una clase.
  Manejamos la lógica del tutorial como si fuera la lógica de la clase Game en otros proyectos,
  de ahí el nombre de la clase.
*/

sprite_renderer* Renderer;

lighting_game::lighting_game(unsigned int width, unsigned int height)
    : Width(width), Height(height)
{

}

lighting_game::~lighting_game()
{

}

void
lighting_game::Init()
{
	lighting_game::m_shaders["colors"] = Shader("Resources/Shaders/colors.vs", "Resources/Shaders/colors.fs", NULL);
	lighting_game::m_shaders["light_cube"] = Shader("Resources/Shaders/light_cube.vs", "Resources/Shaders/light_cube.fs", NULL);

	Renderer = new sprite_renderer(lighting_game::m_shaders);

    /* UNIFORMS DE LIGHT_CUBE */
    lighting_game::m_shaders["light_cube"].Use();

    // projection transformation
    glm::mat4 projection = glm::perspective(glm::radians(45.0f), (float)this->Width/ (float)this->Height, 0.1f, 100.0f);
    //view transformation
    glm::mat4 view = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, -5.0f));
    //model transformation
    glm::mat4 model = glm::mat4(1.0f);

    lighting_game::m_shaders["light_cube"].SetMatrix4("projection", projection);
    lighting_game::m_shaders["light_cube"].SetMatrix4("view", view);
    model = glm::translate(model, glm::vec3(1.2f, 1.0f, 2.0f));
    model = glm::scale(model, glm::vec3(0.2f));
    lighting_game::m_shaders["light_cube"].SetMatrix4("model", model);

    /* UNIFORMS DE COLORS */
    lighting_game::m_shaders["colors"].Use();
    lighting_game::m_shaders["colors"].SetVector3f("objectColor", 1.0f, 0.5f, 0.31f);
    lighting_game::m_shaders["colors"].SetVector3f("lightColor", 1.0f, 1.0f, 1.0f);
    lighting_game::m_shaders["colors"].SetVector3f("lightPos", 1.2f, 1.0f, 2.0f);
    lighting_game::m_shaders["colors"].SetMatrix4("projection", projection);
    lighting_game::m_shaders["colors"].SetMatrix4("view", view);
    model = glm::mat4(1.0f);
    model = glm::rotate(model, glm::radians(45.0f), glm::vec3(0.5f, 0.5f, 0.0f));
    lighting_game::m_shaders["colors"].SetMatrix4("model", model);

}

void
lighting_game::ProcessInput(float dt, bool keys[1024])
{

}

void
lighting_game::Update(float dt)
{


}

void
lighting_game::Render()
{
    Renderer->drawSprite();
}