#ifndef Shader_CLASS_H
#define Shader_CLASS_H

#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h> 
#include <string>
#include <sstream>
#include <fstream>
#include <cerrno>

std::string get_file_contents(const char* filename);

class Shader
{
	public:
	GLuint ID;
	  Shader(const char* vertexFile, const char* fragmentFile);

	void Activate();
	void Delete();
};

#endif // !Shader_CLASS_H

