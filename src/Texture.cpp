#include "../include/Texture.h"

Texture::Texture()
    :t_width(0), t_height(0){
    // Assign ID to 1 texture
    glGenTextures(1, &this->ID);
}
void Texture::generate(GLuint width, GLuint height, unsigned char* data) {
    // Pass width and height to object's width and height
    this->t_width = width;
    this->t_height = height;

    // Bind texture
    glBindTexture(GL_TEXTURE_2D, this->ID);

    // Set texture wrapping
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT); // x-axis wrapping
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT); // y-axis wrapping
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST); //scaling up behavior
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR); // scaling down behavior
    
    // Generate texture
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
    /* args: Glenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, 
     * GLenum format, GLenum type, const void *pixels*/

    // Generate mipmaps for texture
    glGenerateMipmap(GL_TEXTURE_2D);

    // Unbind texture
    glBindTexture(GL_TEXTURE_2D, 0);
}

void Texture::bind() const {
    glBindTexture(GL_TEXTURE_2D, this->ID);
}
