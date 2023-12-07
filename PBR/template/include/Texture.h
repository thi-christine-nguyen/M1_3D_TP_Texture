#ifndef TEXTURE_H_DEFINED
#define TEXTURE_H_DEFINED

#include <string>
#include <GL/glew.h>
#include <vector>

GLuint loadTexture2DFromFilePath(const std::string& path);
GLuint loadNormaleFromFilePath(const std::string& path);
GLuint loadCubemap(const std::vector< std::string> faces);

void setDefaultTexture2DParameters(GLuint texture);

#endif
