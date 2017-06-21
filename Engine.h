#pragma once
#include <GLFW/glfw3.h>

class Engine {
    private:
        // Game Window
        GLFWwindow* m_Window;
        
        // Internal functions, only use in Engine 
        void input();
        void update(double seconds);
        void draw(); 
        
    public: 
        // Engine constructor
        Engine();

        // Timing variables
        double current_time;
        double delta_time;
        double last_time;

        // Calls private functions
        void start();

};
