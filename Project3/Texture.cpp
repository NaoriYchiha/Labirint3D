#include "Texture.h"


Texture::Texture(const char* image, GLenum texType, GLenum slot, GLenum format, GLenum pixelType) {
	//Textures
	
	type = texType;
	int widthQWERTY, heightQWERTY, numColCh;
	stbi_set_flip_vertically_on_load(true);
	unsigned char* bytes = stbi_load(image, &widthQWERTY, &heightQWERTY, &numColCh, 0);
	
	glGenTextures(1, &ID);
	glActiveTexture(slot);
	glBindTexture(type, ID);

	glTexParameteri(type, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(type, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	glTexParameteri(type, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(type, GL_TEXTURE_WRAP_T, GL_REPEAT);


	
	glTexImage2D(type, 0, GL_RGBA, widthQWERTY, heightQWERTY, 0, GL_RGBA, GL_UNSIGNED_BYTE, bytes);
	glGenerateMipmap(type);

	stbi_image_free(bytes);
	glBindTexture(type, 0);
}

void Texture::texUnit(Shader shader, const char* uniform, GLuint unit)
{
	GLuint texUni = glGetUniformLocation(shader.ID, uniform);
	shader.Activate();
	glUniform1i(texUni, unit);
}

void Texture::Bind()
{
	glBindTexture(type, ID);
}

// Unbinds the VAO
void Texture::UnBind()
{
	glBindTexture(type, 0);
}

// Deletes the VAO
void Texture::Delete()
{
	glDeleteTextures(1, &ID);
}
