#pragma once
#include <GL/glew.h>

#include <map>
#include <string>

#include "Texture.h"
#include "Shader.h"

using namespace std;

class ResourceManager {
    private:
        ResourceManager();
        // Loads texture from image file
        static Texture loadTextureFromFile(const char* file);
        // Loads shaders from various files
        static Shader loadShaderFromFile(const GLchar* vFile, const GLchar* fFile, const GLchar* gFile = nullptr);
    public:
        // Resource storage
        static map<string, Texture> Textures;
        static map<string, Shader> Shaders;
        // Texture functions
        static Texture loadTexture(const char* image, string name);
        static Texture getTexture(string name);
        // Shader functions
        static Shader loadShader(const GLchar* vFile, const GLchar* fFile, const GLchar* gFile, string name);
        static Shader getShader(string name);
        // De-allocate all loaded resources
        static void clear();
};
