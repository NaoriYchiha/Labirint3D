#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stb/stb_image.h.txt>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Texture.h"
#include "ShaderClass.h"
#include "VBO.h"
#include "VAO.h"
#include "EBO.h"
#include "Camera.h"
#include "VerticesIndices.h"



const unsigned int width = 1920;
const unsigned int height = 1080; 

GLFWimage load_icon(const char* filename)
{
	GLFWimage image;
	image.pixels = stbi_load(filename, &image.width, &image.height, NULL, 4);
	return image;
}
	
int main() {

	glfwInit();

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);	

	

	//Create a window with name and height/weight of window
	GLFWwindow* window = glfwCreateWindow(width, height, "Love", NULL, NULL);
	if (window == NULL) {
		std::cout << "Failed to create glfw window" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);
	
	
	//Load GLAD to configurate OpenGL
	gladLoadGL();
		//screen window size
		glViewport(0, 0, width, height);

		GLFWimage images[2];
		images[0] = load_icon("qwerty.png");
		images[1] = load_icon("qwerty.png");

		glfwSetWindowIcon(window, 2, images);


		Shader shaderProgram("default.vert", "default.frag");
		VAO VAO1;
		VAO1.Bind();
		VBO VBO1(CubeVertices, SizeCubeVertices);
		EBO EBO1(CubeIndices, SizeCubeIndices);

		VAO1.LinkAttrib(VBO1, 0, 3, GL_FLOAT, 8 * sizeof(float), (void*)0);
		VAO1.LinkAttrib(VBO1, 1, 3, GL_FLOAT, 8 * sizeof(float), (void*)(3 * sizeof(float)));
		VAO1.LinkAttrib(VBO1, 2, 2, GL_FLOAT, 8 * sizeof(float), (void*)(6 * sizeof(float)));
		VAO1.Unbind();
		VBO1.Unbind();
		EBO1.Unbind();

		VAO VAO2;
		VAO2.Bind();
		VBO VBO2(FloorVertices, SizeFloorVertices);
		EBO EBO2(FloorIndices, SizeFloorIndices);


		VAO2.LinkAttrib(VBO2, 0, 3, GL_FLOAT, 8 * sizeof(float), (void*)0);
		VAO2.LinkAttrib(VBO2, 1, 3, GL_FLOAT, 8 * sizeof(float), (void*)(3 * sizeof(float)));
		VAO2.LinkAttrib(VBO2, 2, 2, GL_FLOAT, 8 * sizeof(float), (void*)(6 * sizeof(float)));
		VAO2.Unbind();
		VBO2.Unbind();
		EBO2.Unbind();


		VAO VAO3;
		VAO3.Bind();
		VBO VBO3(WallVertices, SizeWallVertices);
		EBO EBO3(WallIndices, SizeWallIndices);


		VAO3.LinkAttrib(VBO3, 0, 3, GL_FLOAT, 8 * sizeof(float), (void*)0);
		VAO3.LinkAttrib(VBO3, 1, 3, GL_FLOAT, 8 * sizeof(float), (void*)(3 * sizeof(float)));
		VAO3.LinkAttrib(VBO3, 2, 2, GL_FLOAT, 8 * sizeof(float), (void*)(6 * sizeof(float)));
		VAO3.Unbind();
		VBO3.Unbind();
		EBO3.Unbind();

		VAO MenuVAO;
		MenuVAO.Bind();

		VBO MenuVBO(MenuVertices, SizeMenuVertices);
		EBO MenuEBO(MenuIndices, SizeMenuIndices);

		MenuVAO.LinkAttrib(MenuVBO, 0, 3, GL_FLOAT, 8 * sizeof(float), (void*)0);
		MenuVAO.LinkAttrib(MenuVBO, 1, 3, GL_FLOAT, 8 * sizeof(float), (void*)(3 * sizeof(float)));
		MenuVAO.LinkAttrib(MenuVBO, 2, 2, GL_FLOAT, 8 * sizeof(float), (void*)(6 * sizeof(float)));
		MenuVAO.Unbind();
		MenuVBO.Unbind();
		MenuEBO.Unbind();
		
		VAO ButtonVAO;
		ButtonVAO.Bind();

		VBO ButtonVBO(ButtonVertices, sizeof(SizeButtonVertices));
		EBO ButtonEBO(ButtonIndices, sizeof(SizeButtonIndices));

		ButtonVAO.LinkAttrib(ButtonVBO, 0, 3, GL_FLOAT, 8 * sizeof(float), (void*)0);
		ButtonVAO.LinkAttrib(ButtonVBO, 1, 3, GL_FLOAT, 8 * sizeof(float), (void*)(3 * sizeof(float)));
		ButtonVAO.LinkAttrib(ButtonVBO, 2, 2, GL_FLOAT, 8 * sizeof(float), (void*)(6 * sizeof(float)));
		ButtonVAO.Unbind();
		ButtonVBO.Unbind();
		ButtonEBO.Unbind();

		//Textures(image)
		Texture KAMILLA("qwerty.png", GL_TEXTURE_2D, GL_TEXTURE0, GL_RGBA, GL_UNSIGNED_BYTE);
		KAMILLA.texUnit(shaderProgram, "tex0", 0);
		Texture Floor("floor.png", GL_TEXTURE_2D, GL_TEXTURE1, GL_RGBA, GL_UNSIGNED_BYTE);
		Floor.texUnit(shaderProgram, "tex1", 1);
		Texture Wall("wall.png", GL_TEXTURE_2D, GL_TEXTURE2, GL_RGBA, GL_UNSIGNED_BYTE);
		Wall.texUnit(shaderProgram, "tex2", 2);
		Texture Preview("preview.png", GL_TEXTURE_2D, GL_TEXTURE3, GL_RGBA, GL_UNSIGNED_BYTE);
		Preview.texUnit(shaderProgram, "tex3", 3);
		Texture Button1("kon.png", GL_TEXTURE_2D, GL_TEXTURE4, GL_RGBA, GL_UNSIGNED_BYTE);
		Button1.texUnit(shaderProgram, "tex4", 4);

		glEnable(GL_DEPTH_TEST);

		glm::vec3 camPos = glm::vec3(-24.0f, 0.0f, 24.0f);

		Camera camera(width, height, camPos);
		Camera MenuCamera(width, height, glm::vec3(0.0f, 0.0f, 2.0f));

		bool isMenuDisplayed = true;

		GLenum error = glGetError();
		if (error != GL_NO_ERROR) {
			std::cout << "OpenGL error: " << error << std::endl;
		}

		//Main while loop
		while (!glfwWindowShouldClose(window))
		{
			glClearColor(0.7f, 0.74f, 1.0f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
			if (isMenuDisplayed) // Если флаг установлен в true, отображаем меню
			{
				shaderProgram.Activate();
				MenuCamera.Matrix(45.0f, 0.1f, 100.0f, shaderProgram, "camMatrix");

				Preview.Bind();
				MenuVAO.Bind();
				glDrawElements(GL_TRIANGLES, SizeMenuIndices / sizeof(int), GL_UNSIGNED_INT, 0);
		
				Button1.Bind();
				ButtonVAO.Bind();
				glDrawElements(GL_TRIANGLES, SizeButtonIndices / sizeof(int), GL_UNSIGNED_INT, 0);

			}
			else // Если флаг установлен в false, отображаем игровой мир
			{
				shaderProgram.Activate();
				camera.Inputs(window);
				camera.Matrix(45.0f, 0.01f, 100.0f, shaderProgram, "camMatrix");

				KAMILLA.Bind();
				VAO1.Bind();
				glDrawElements(GL_TRIANGLES, SizeCubeIndices / sizeof(int), GL_UNSIGNED_INT, 0);

				Floor.Bind();
				VAO2.Bind();
				glDrawElements(GL_TRIANGLES, SizeFloorIndices / sizeof(int), GL_UNSIGNED_INT, 0);

				Wall.Bind();
				VAO3.Bind();
				glDrawElements(GL_TRIANGLES, SizeWallIndices / sizeof(int), GL_UNSIGNED_INT, 0);
			}

			glfwSwapBuffers(window);
			//Take care of all GLFW events
			glfwPollEvents();

			if (glfwGetKey(window, GLFW_KEY_ENTER) == GLFW_PRESS)
			{
			isMenuDisplayed = false; // Если пользователь нажал Enter, переключаем флаг в false
			};
		}

	

	MenuVAO.Delete();
	MenuVBO.Delete();
	MenuEBO.Delete();
	ButtonVAO.Delete();
	ButtonVBO.Delete();
	ButtonEBO.Delete();
	VAO1.Delete();
	VBO1.Delete();
	EBO1.Delete();
	VAO2.Delete();
	VBO2.Delete();
	EBO2.Delete();
	VAO3.Delete();
	VBO3.Delete();
	EBO3.Delete();
	shaderProgram.Delete();
	KAMILLA.Delete();
	Floor.Delete();
	Wall.Delete();
	Preview.Delete();
	Button1.Delete();

	
	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;
}