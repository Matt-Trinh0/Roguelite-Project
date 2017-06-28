#include "../include/Shader.h"

Shader::Shader() {}

Shader &Shader::Use() { 
    glUseProgram(this->ID);
    return *this;
}

void Shader::compile(const GLchar* vertexSource, const GLchar* fragmentSource, const GLchar* geometrySource) {
    // Load and compile shaders
    sVertex = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(sVertex, 1, &vertexSource, NULL);
    // args: GLuint shader, GLsizei count, const GLchar **string, const GLint *length
    glCompileShader(sVertex);
    // TODO check compiling errors
    sFragment = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(sFragment, 1, &fragmentSource, NULL);
    glCompileShader(sFragment);
    // TODO check compiling errors
    if (geometrySource != nullptr) {
        sGeometry = glCreateShader(GL_GEOMETRY_SHADER);
        glShaderSource(sGeometry, 1, &geometrySource, NULL);
        glCompileShader(sGeometry);
        // TODO check compiling errors
    }
    // Create program
    this->ID = glCreateProgram();
    // Attach shaders to program
    glAttachShader(this->ID, sVertex);
    glAttachShader(this->ID, sFragment);
    if (geometrySource != nullptr)
        glAttachShader(this->ID, sGeometry);
    // Link shaders together into program
    glLinkProgram(this->ID);
    // TODO check compiling errors
    // Delete shaders to free memory
    glDeleteShader(sVertex);
    glDeleteShader(sFragment);
    if (geometrySource != nullptr)
        glDeleteShader(sGeometry);
} 

// Utility functions
void Shader::setFloat(const char* name, GLfloat value, GLboolean useShader) {
    if (useShader) 
        this->Use();
    glUniform1f(glGetUniformLocation(this->ID, name), value);
}

void Shader::setInt(const char* name, GLint value, GLboolean useShader) {
    if (useShader) 
        this->Use();
    glUniform1i(glGetUniformLocation(this->ID, name), value);
}

void Shader::setVec2f(const char* name, GLfloat x, GLfloat y, GLboolean useShader) {
    if (useShader) 
        this->Use();
    glUniform2f(glGetUniformLocation(this->ID, name), x, y);
}

void Shader::setVec2f(const char* name, vec2 &value, GLboolean useShader) {
    if (useShader) 
        this->Use();
    glUniform2f(glGetUniformLocation(this->ID, name), value.x, value.y);
}

void Shader::setVec3f(const char* name, GLfloat x, GLfloat y, GLfloat z, GLboolean useShader) {
    if (useShader) 
        this->Use();
    glUniform3f(glGetUniformLocation(this->ID, name), x, y, z);
}

void Shader::setVec3f(const char* name, vec3 &value, GLboolean useShader) {
    if (useShader) 
        this->Use();
    glUniform3f(glGetUniformLocation(this->ID, name), value.x, value.y, value.z);
}

void Shader::setVec4f(const char* name, GLfloat x, GLfloat y, GLfloat z, GLfloat w, GLboolean useShader) {
    if (useShader) 
        this->Use();
    glUniform4f(glGetUniformLocation(this->ID, name), x, y, z, w);
}

void Shader::setVec4f(const char* name, vec4 &value, GLboolean useShader) {
    if (useShader) 
        this->Use();
    glUniform4f(glGetUniformLocation(this->ID, name), value.x, value.y, value.z, value.w);
}
