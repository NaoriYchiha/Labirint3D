#pragma once
#ifndef TEXTURE_CLASS_H
#define TEXTURE_CLASS_H

#include<glad/glad.h>
#include<stb/stb_image.h.txt>

#include "ShaderClass.h"

class Texture
{
public:
	GLuint ID;
	GLenum type;
	Texture(const char* image, GLenum texType, GLenum slot, GLenum format, GLenum pixelType);

	void texUnit(Shader shader, const char* uniform, GLuint unit);
	void Bind();
	void UnBind();
	void Delete();
}; 

#endif // !TEXTURE_CLASS_H
