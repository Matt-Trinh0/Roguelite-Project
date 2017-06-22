#include "../include/Engine.h"

void Engine::draw() {

    // Clear previous frame
    glClear(GL_COLOR_BUFFER_BIT);

    // Render below

    // Swap current frame (front buffer) and next frame (back buffer)
    glfwSwapBuffers(m_Window);
    // Rate of the buffer swap
    glfwSwapInterval(1); /* Set to 1 to prevent screen tearing, higher
                            values can cause extra input lag */
};
