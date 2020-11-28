#include "glfw_window.h"

void
glfw_window::init(int width, int height, const std::string& title)
{
    /* Initialize the library */
    if (!glfwInit())
        std::cout << "ERROR initializing GLFW" << std::endl;

    // Configure library
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    /* Create a windowed mode window and its OpenGL context */
    m_window = glfwCreateWindow(width, height, title.c_str(), NULL, NULL);
    if (!m_window)
    {
        glfwTerminate();
        std::cout << "ERROR creating an OpenGL window object" << std::endl;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(m_window);

    /*Inicializar glew después de tener un contexto y ventana establecidos para opengl*/
    GLenum err = glewInit();
    if (GLEW_OK != err)
    {
        fprintf(stderr, "Error: %s\n", glewGetErrorString(err));
    }
    fprintf(stdout, "Status: Using GLEW %s con version de OpenGL %s\n", glewGetString(GLEW_VERSION), glGetString(GL_VERSION));

    /*keyboard*/
    /*a través de esta función pasamos mediante el objeto window la instancia de nuestra clase*/
    glfwSetWindowUserPointer(m_window, this);
    glfwSetKeyCallback(m_window, key_callback);

    /*Inicializar estado de OpenGL*/
    glClearColor(0.0f, 0.15f, 0.3f, 1.0f);
    glViewport(0, 0, width, height);
    
    glEnable(GL_DEPTH_TEST);
}

void
glfw_window::clear()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void
glfw_window::swapBuffers()
{
    glfwSwapBuffers(m_window);
}

void
glfw_window::events()
{
    glfwPollEvents();
}

bool
glfw_window::isClosed()
{
    return glfwWindowShouldClose(m_window);
}

void
glfw_window::delete_window()
{
    glfwTerminate();
}

void
glfw_window::key_callback(GLFWwindow* window, int key, int scancode, int action, int mode)
{
    glfw_window* display = static_cast<glfw_window*>(glfwGetWindowUserPointer(window));

    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
    if (key >= 0 && key < 1024)
    {
        if (action == GLFW_PRESS)
            display->m_keys[key] = true;
        else if (action == GLFW_RELEASE)
            display->m_keys[key] = false;
    }
}

bool*
glfw_window::get_keys()
{
    return glfw_window::m_keys;
}