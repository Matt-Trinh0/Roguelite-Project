#include "../include/ResourceManager.h"
#include <SOIL/SOIL.h>

#include <iostream>
#include <sstream>
#include <fstream>

// Texture and Shader storage
map<string, Texture> ResourceManager::Textures;
map<string, Shader> ResourceManager::Shaders;

Texture ResourceManager::loadTexture(const char* file, string name) {
   Textures[name] = loadTextureFromFile(file);
   return Textures[name]; 
}

Texture ResourceManager::getTexture(string name) {
    return Textures[name];
}

// TODO add support of alpha channel
Texture ResourceManager::loadTextureFromFile(const char* file) {
    // Create texture object
    Texture texture;
    // Load image
    int width, height, nrChannels;
    unsigned char* image = SOIL_load_image(file, &width, &height, &nrChannels, SOIL_LOAD_RGB);
    // Generate image
    texture.generate(width, height, image);
    // Free image from memory
    SOIL_free_image_data(image);
    return texture;
}

Shader ResourceManager::loadShader(const GLchar* vFile, const GLchar* fFile, const GLchar* gFile, string name) {
    Shaders[name] = loadShaderFromFile(vFile, fFile, gFile);
    return Shaders[name];
}

Shader ResourceManager::getShader(string name) {
    return Shaders[name];
}

Shader ResourceManager::loadShaderFromFile(const GLchar* vFile, const GLchar* fFile, const GLchar* gFile) {
    /* Get source code from files */
    string vCode;
    string fCode;
    string gCode;
    // TODO handle exceptions
    // Open files
    ifstream vertexShaderFile(vFile);
    ifstream fragmentShaderFile(fFile);
    stringstream vStream, fStream;
    // Read and buffer contents of shader files into streams
    vStream << vertexShaderFile.rdbuf();
    fStream << fragmentShaderFile.rdbuf();
    // Close files
    vertexShaderFile.close();
    fragmentShaderFile.close();
    // Convert streams into strings
    vCode = vStream.str();
    fCode = fStream.str();
    // Check for geometry shader and do the same
    if (gFile != nullptr) {
        ifstream geometryShaderFile(gFile);
        stringstream gStream;
        gStream << geometryShaderFile.rdbuf();
        geometryShaderFile.close();
        gCode = gStream.str();
    }
    // Convert strings into char arrays to pass into the compile function
    const GLchar* vShaderCode = vCode.c_str();
    const GLchar* fShaderCode = fCode.c_str();
    const GLchar* gShaderCode = gCode.c_str();
    /* Compile into shader object */
    Shader shader;
    shader.compile(vShaderCode, fShaderCode, gFile != nullptr ? gShaderCode : nullptr);
    return shader;
}

void ResourceManager::clear() {
    // Delete all textures from Textures
    for (auto i : Textures)
        glDeleteTextures(1, &i.second.ID);
}
