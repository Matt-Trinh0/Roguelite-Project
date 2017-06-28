#include "../include/Engine.h"

Engine::Engine() {
    // Initialize GLFW
    if (!glfwInit()) 
        glfwTerminate();
    
    // Get screen resolution
    const GLFWvidmode* mode = glfwGetVideoMode(glfwGetPrimaryMonitor());

    int window_x = mode->width;
    int window_y = mode->height;
    
    // Create window
    m_Window = glfwCreateWindow(window_x, window_y, "Test", NULL, NULL);
    if (!m_Window) {
        glfwTerminate();
    }
    
    // Game states
    enum gameState {game_paused, game_active};

};

void Engine::start() {
    // Loop until user closes window
    while (!glfwWindowShouldClose(m_Window)) {

        // Calculate delta time or the time between each frame
        current_time = glfwGetTime();
        delta_time = current_time - last_time;
        last_time = current_time;
        
        input(); // Handle player input
        update(delta_time); // Update frame
        draw(); // Render the new frame
    }

    glfwTerminate();

};
