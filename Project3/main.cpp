#include <iostream>
#include <fstream>
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



const unsigned int width = 1280;
const unsigned int height = 960; 

int wins = 0;
int loses = 0;

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
		images[0] = load_icon("preview.png");
		images[1] = load_icon("preview.png");

		glfwSetWindowIcon(window, 2, images);

		std::ofstream file("time.txt");

		Shader shaderProgram("default.vert", "default.frag");
		VAO VAO1;
		VAO1.Bind();
		VBO VBO1(MapFinishVertices, SizeMapFinishVertices);
		EBO EBO1(MapFinishIndices, SizeMapFinishIndices);

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

		VAO FinishVAO;
		FinishVAO.Bind();

		VBO FinishVBO(FinishVertices, SizeFinishVertices);
		EBO FinishEBO(FinishIndices, SizeFinishIndices);

		FinishVAO.LinkAttrib(FinishVBO, 0, 3, GL_FLOAT, 8 * sizeof(float), (void*)0);
		FinishVAO.LinkAttrib(FinishVBO, 1, 3, GL_FLOAT, 8 * sizeof(float), (void*)(3 * sizeof(float)));
		FinishVAO.LinkAttrib(FinishVBO, 2, 2, GL_FLOAT, 8 * sizeof(float), (void*)(6 * sizeof(float)));
		FinishVAO.Unbind();
		FinishVBO.Unbind();
		FinishEBO.Unbind();

		VAO PlayButtonVAO;
		PlayButtonVAO.Bind();

		VBO PlayButtonVBO(PlayButtonVertices, SizePlayButtonVertices);
		EBO PlayButtonEBO(PlayButtonIndices, SizePlayButtonIndices);

		PlayButtonVAO.LinkAttrib(PlayButtonVBO, 0, 3, GL_FLOAT, 8 * sizeof(float), (void*)0);
		PlayButtonVAO.LinkAttrib(PlayButtonVBO, 1, 3, GL_FLOAT, 8 * sizeof(float), (void*)(3 * sizeof(float)));
		PlayButtonVAO.LinkAttrib(PlayButtonVBO, 2, 2, GL_FLOAT, 8 * sizeof(float), (void*)(6 * sizeof(float)));
		PlayButtonVAO.Unbind();
		PlayButtonVBO.Unbind();
		PlayButtonEBO.Unbind();

		VAO ExitButtonVAO;
		ExitButtonVAO.Bind();

		VBO ExitButtonVBO(ExitButtonVertices, SizeExitButtonVertices);
		EBO ExitButtonEBO(ExitButtonIndices, SizeExitButtonIndices);

		ExitButtonVAO.LinkAttrib(ExitButtonVBO, 0, 3, GL_FLOAT, 8 * sizeof(float), (void*)0);
		ExitButtonVAO.LinkAttrib(ExitButtonVBO, 1, 3, GL_FLOAT, 8 * sizeof(float), (void*)(3 * sizeof(float)));
		ExitButtonVAO.LinkAttrib(ExitButtonVBO, 2, 2, GL_FLOAT, 8 * sizeof(float), (void*)(6 * sizeof(float)));
		ExitButtonVAO.Unbind();
		ExitButtonVBO.Unbind();
		ExitButtonEBO.Unbind();

		//Textures(image)
		Texture Finish("finish.png", GL_TEXTURE_2D, GL_TEXTURE0, GL_RGBA, GL_UNSIGNED_BYTE);
		Finish.texUnit(shaderProgram, "tex0", 0);
		Texture Floor("floor.png", GL_TEXTURE_2D, GL_TEXTURE1, GL_RGBA, GL_UNSIGNED_BYTE);
		Floor.texUnit(shaderProgram, "tex1", 1);
		Texture Wall("wall.png", GL_TEXTURE_2D, GL_TEXTURE2, GL_RGBA, GL_UNSIGNED_BYTE);
		Wall.texUnit(shaderProgram, "tex2", 2);
		Texture Preview("preview.png", GL_TEXTURE_2D, GL_TEXTURE3, GL_RGBA, GL_UNSIGNED_BYTE);
		Preview.texUnit(shaderProgram, "tex3", 3);
		Texture PlayButton("PlayButton.png", GL_TEXTURE_2D, GL_TEXTURE4, GL_RGBA, GL_UNSIGNED_BYTE);
		PlayButton.texUnit(shaderProgram, "tex4", 4);
		Texture ExitButton("ExitButton.png", GL_TEXTURE_2D, GL_TEXTURE5, GL_RGBA, GL_UNSIGNED_BYTE);
		ExitButton.texUnit(shaderProgram, "tex5", 5);

		glEnable(GL_DEPTH_TEST);

		glm::vec3 startCamPos = glm::vec3(24.0f, 0.0f, 24.0f);
		glm::vec3 startOrientation = glm::vec3(0.0f, 0.0f, -0.1f);

		double lastTime = glfwGetTime();
		

		Camera camera(width, height, startCamPos);
		Camera MenuCamera(width, height, glm::vec3(0.0f, 0.0f, 2.0f));
		Camera FinishCamera(width, height, glm::vec3(0.0f, 0.0f, 2.0f));

		GLenum error = glGetError();
		if (error != GL_NO_ERROR) {
			std::cout << "OpenGL error: " << error << std::endl;
		}
	

		//Main while loop
while (!glfwWindowShouldClose(window))	
{
	glClearColor(0.7f, 0.74f, 1.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	double currentTime = glfwGetTime();

	if (MenuCamera.PlayButtonClick(window)) // Если флаг установлен в true, отображаем меню
	{
		shaderProgram.Activate();
		MenuCamera.Matrix(45.0f, 0.1f, 100.0f, shaderProgram, "camMatrix");

		Preview.Bind();
		MenuVAO.Bind();
		glDrawElements(GL_TRIANGLES, SizeMenuIndices / sizeof(int), GL_UNSIGNED_INT, 0);

		PlayButton.Bind();
		PlayButtonVAO.Bind();
		glDrawElements(GL_TRIANGLES, SizePlayButtonIndices / sizeof(int), GL_UNSIGNED_INT, 0);

		ExitButton.Bind();
		ExitButtonVAO.Bind();
		glDrawElements(GL_TRIANGLES, SizeExitButtonIndices / sizeof(int), GL_UNSIGNED_INT, 0);
		
		if (MenuCamera.ExitButtonClick(window))
		{
			glfwSetWindowShouldClose(window, GL_TRUE);
		}
	}
	
	else // Если флаг установлен в false, отображаем игровой мир
	{
		if (camera.player_reached_finish())
		{
			shaderProgram.Activate();
			FinishCamera.Matrix(45.0f, 0.1f, 100.0f, shaderProgram, "camMatrix");

			Finish.Bind();
			FinishVAO.Bind();
			glDrawElements(GL_TRIANGLES, SizeFinishIndices / sizeof(int), GL_UNSIGNED_INT, 0);

			if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS)
			{
				camera.Position = startCamPos;
				camera.Orientation = startOrientation;
				lastTime = currentTime;
				wins++;
				file << "Finish time: " << lastTime << " seconds." << std::endl << "Wins: " << wins << std::endl;
			};
		}
		else 
		{
			shaderProgram.Activate();
			camera.Inputs(window);
			camera.Matrix(45.0f, 0.01f, 100.0f, shaderProgram, "camMatrix");

			Finish.Bind();
			VAO1.Bind();
			glDrawElements(GL_TRIANGLES, SizeMapFinishIndices / sizeof(int), GL_UNSIGNED_INT, 0);

			Floor.Bind();
			VAO2.Bind();
			glDrawElements(GL_TRIANGLES, SizeFloorIndices / sizeof(int), GL_UNSIGNED_INT, 0);

			Wall.Bind();
			VAO3.Bind();
			glDrawElements(GL_TRIANGLES, SizeWallIndices / sizeof(int), GL_UNSIGNED_INT, 0);
			
		}
	}

	
	glfwSwapBuffers(window);
		//Take care of all GLFW events
	glfwPollEvents();

	if (glfwWindowShouldClose(window) && !camera.player_reached_finish())
	{
		loses++;
		file  << "Loses: " << loses << std::endl;
	};
}

	
	file.close();
	MenuVAO.Delete();
	MenuVBO.Delete();
	MenuEBO.Delete();
	FinishVAO.Delete();
	FinishVBO.Delete();
	FinishEBO.Delete();
	PlayButtonVAO.Delete();
	PlayButtonVBO.Delete();
	PlayButtonEBO.Delete();
	ExitButtonVAO.Delete();
	ExitButtonVBO.Delete();
	ExitButtonEBO.Delete();
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
	Finish.Delete();
	Floor.Delete();
	Wall.Delete();
	Preview.Delete();
	PlayButton.Delete();
	ExitButton.Delete();

	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;
}