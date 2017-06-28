#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>

class Texture {
    public:
        GLuint ID; // texture id
        // texture height and weight
        GLuint t_width;
        GLuint t_height;
        Texture();

        void generate(GLuint width, GLuint height, unsigned char* data);
        void bind() const;
};
