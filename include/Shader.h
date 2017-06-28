#pragma once

#include <string>

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

using namespace std;
using namespace glm;

class Shader {
    public:
        GLuint ID; // Shader ID
        GLuint sVertex, sFragment, sGeometry; // Vertex, Fragment, and Geometry shaders
        Shader();
        Shader &Use(); // Use shader
        
        void compile(const GLchar* vertexSource, const GLchar* fragmentSource, const GLchar* geometrySource = nullptr);
        // Utility functions
        // Note: Don't use strings as names here because the arg for glGetUniformLocation requires a char array
        void setFloat(const char* name, GLfloat value, GLboolean useShader = false);
        void setInt(const char* name, GLint value, GLboolean useShader = false);
        void setVec2f(const char* name, GLfloat x, GLfloat y, GLboolean = false);
        void setVec2f(const char* name, vec2 &value, GLboolean useShader = false);
        void setVec3f(const char* name, GLfloat x, GLfloat y, GLfloat z, GLboolean = false);
        void setVec3f(const char* name, vec3 &value, GLboolean useShader = false);
        void setVec4f(const char* name, GLfloat x, GLfloat y, GLfloat z, GLfloat w, GLboolean = false);
        void setVec4f(const char* name, vec4 &value, GLboolean = false);
    private:
        // TODO write this later
        void checkCompileErrors(GLuint object, string type);
};
