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



unsigned int width = 1920, height = 1080;

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
		images[0] = load_icon("LabTextures/ICON.png");
		images[1] = load_icon("LabTextures/ICON.png");

		glfwSetWindowIcon(window, 2, images);

		std::ofstream file("time.txt");

		Shader shaderProgram("default.vert", "default.frag");
		VAO MapFinishVAO;
		MapFinishVAO.Bind();
		VBO MapFinishVBO(MapFinishVertices, SizeMapFinishVertices);
		EBO MapFinishEBO(MapFinishIndices, SizeMapFinishIndices);

		MapFinishVAO.LinkAttrib(MapFinishVBO, 0, 3, GL_FLOAT, 8 * sizeof(float), (void*)0);
		MapFinishVAO.LinkAttrib(MapFinishVBO, 1, 3, GL_FLOAT, 8 * sizeof(float), (void*)(3 * sizeof(float)));
		MapFinishVAO.LinkAttrib(MapFinishVBO, 2, 2, GL_FLOAT, 8 * sizeof(float), (void*)(6 * sizeof(float)));
		MapFinishVAO.Unbind();
		MapFinishVBO.Unbind();
		MapFinishEBO.Unbind();

		VAO FloorVAO;
		FloorVAO.Bind();
		VBO FloorVBO(FloorVertices, SizeFloorVertices);
		EBO FloorEBO(FloorIndices, SizeFloorIndices);


		FloorVAO.LinkAttrib(FloorVBO, 0, 3, GL_FLOAT, 8 * sizeof(float), (void*)0);
		FloorVAO.LinkAttrib(FloorVBO, 1, 3, GL_FLOAT, 8 * sizeof(float), (void*)(3 * sizeof(float)));
		FloorVAO.LinkAttrib(FloorVBO, 2, 2, GL_FLOAT, 8 * sizeof(float), (void*)(6 * sizeof(float)));
		FloorVAO.Unbind();
		FloorVBO.Unbind();
		FloorEBO.Unbind();


		VAO WallVAO;
		WallVAO.Bind();
		VBO WallVBO(WallVertices, SizeWallVertices);
		EBO WallEBO(WallIndices, SizeWallIndices);


		WallVAO.LinkAttrib(WallVBO, 0, 3, GL_FLOAT, 8 * sizeof(float), (void*)0);
		WallVAO.LinkAttrib(WallVBO, 1, 3, GL_FLOAT, 8 * sizeof(float), (void*)(3 * sizeof(float)));
		WallVAO.LinkAttrib(WallVBO, 2, 2, GL_FLOAT, 8 * sizeof(float), (void*)(6 * sizeof(float)));
		WallVAO.Unbind();
		WallVBO.Unbind();
		WallEBO.Unbind();

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

		VAO SettingsMenuVAO;
		SettingsMenuVAO.Bind();

		VBO SettingsMenuVBO(SettingsMenuVertices, SizeSettingsMenuVertices);
		EBO SettingsMenuEBO(SettingsMenuIndices, SizeSettingsMenuIndices);

		SettingsMenuVAO.LinkAttrib(SettingsMenuVBO, 0, 3, GL_FLOAT, 8 * sizeof(float), (void*)0);
		SettingsMenuVAO.LinkAttrib(SettingsMenuVBO, 1, 3, GL_FLOAT, 8 * sizeof(float), (void*)(3 * sizeof(float)));
		SettingsMenuVAO.LinkAttrib(SettingsMenuVBO, 2, 2, GL_FLOAT, 8 * sizeof(float), (void*)(6 * sizeof(float)));
		SettingsMenuVAO.Unbind();
		SettingsMenuVBO.Unbind();
		SettingsMenuEBO.Unbind();

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
		
		VAO SettingsButtonVAO;
		SettingsButtonVAO.Bind();

		VBO SettingsButtonVBO(SettingsButtonVertices, SizeSettingsButtonVertices);
		EBO SettingsButtonEBO(SettingsButtonIndices, SizeSettingsButtonIndices);

		SettingsButtonVAO.LinkAttrib(SettingsButtonVBO, 0, 3, GL_FLOAT, 8 * sizeof(float), (void*)0);
		SettingsButtonVAO.LinkAttrib(SettingsButtonVBO, 1, 3, GL_FLOAT, 8 * sizeof(float), (void*)(3 * sizeof(float)));
		SettingsButtonVAO.LinkAttrib(SettingsButtonVBO, 2, 2, GL_FLOAT, 8 * sizeof(float), (void*)(6 * sizeof(float)));
		SettingsButtonVAO.Unbind();
		SettingsButtonVBO.Unbind();
		SettingsButtonEBO.Unbind();

		VAO Resolution800x600ButtonVAO;
		Resolution800x600ButtonVAO.Bind();

		VBO Resolution800x600ButtonVBO(Resolution800x600ButtonVertices, SizeResolution800x600ButtonVertices);
		EBO Resolution800x600ButtonEBO(Resolution800x600ButtonIndices, SizeResolution800x600ButtonIndices);

		Resolution800x600ButtonVAO.LinkAttrib(Resolution800x600ButtonVBO, 0, 3, GL_FLOAT, 8 * sizeof(float), (void*)0);
		Resolution800x600ButtonVAO.LinkAttrib(Resolution800x600ButtonVBO, 1, 3, GL_FLOAT, 8 * sizeof(float), (void*)(3 * sizeof(float)));
		Resolution800x600ButtonVAO.LinkAttrib(Resolution800x600ButtonVBO, 2, 2, GL_FLOAT, 8 * sizeof(float), (void*)(6 * sizeof(float)));
		Resolution800x600ButtonVAO.Unbind();
		Resolution800x600ButtonVBO.Unbind();
		Resolution800x600ButtonEBO.Unbind();

		VAO Resolution1280x720ButtonVAO;
		Resolution1280x720ButtonVAO.Bind();

		VBO Resolution1280x720ButtonVBO(Resolution1280x720ButtonVertices, SizeResolution1280x720ButtonVertices);
		EBO Resolution1280x720ButtonEBO(Resolution1280x720ButtonIndices, SizeResolution1280x720ButtonIndices);

		Resolution1280x720ButtonVAO.LinkAttrib(Resolution1280x720ButtonVBO, 0, 3, GL_FLOAT, 8 * sizeof(float), (void*)0);
		Resolution1280x720ButtonVAO.LinkAttrib(Resolution1280x720ButtonVBO, 1, 3, GL_FLOAT, 8 * sizeof(float), (void*)(3 * sizeof(float)));
		Resolution1280x720ButtonVAO.LinkAttrib(Resolution1280x720ButtonVBO, 2, 2, GL_FLOAT, 8 * sizeof(float), (void*)(6 * sizeof(float)));
		Resolution1280x720ButtonVAO.Unbind();
		Resolution1280x720ButtonVBO.Unbind();
		Resolution1280x720ButtonEBO.Unbind();

		VAO Resolution1920x1080ButtonVAO;
		Resolution1920x1080ButtonVAO.Bind();

		VBO Resolution1920x1080ButtonVBO(Resolution1920x1080ButtonVertices, SizeResolution1920x1080ButtonVertices);
		EBO Resolution1920x1080ButtonEBO(Resolution1920x1080ButtonIndices, SizeResolution1920x1080ButtonIndices);

		Resolution1920x1080ButtonVAO.LinkAttrib(Resolution1920x1080ButtonVBO, 0, 3, GL_FLOAT, 8 * sizeof(float), (void*)0);
		Resolution1920x1080ButtonVAO.LinkAttrib(Resolution1920x1080ButtonVBO, 1, 3, GL_FLOAT, 8 * sizeof(float), (void*)(3 * sizeof(float)));
		Resolution1920x1080ButtonVAO.LinkAttrib(Resolution1920x1080ButtonVBO, 2, 2, GL_FLOAT, 8 * sizeof(float), (void*)(6 * sizeof(float)));
		Resolution1920x1080ButtonVAO.Unbind();
		Resolution1920x1080ButtonVBO.Unbind();
		Resolution1920x1080ButtonEBO.Unbind();

		//Textures(image)
		Texture Finish("LabTextures/finish.png", GL_TEXTURE_2D, GL_TEXTURE0, GL_RGBA, GL_UNSIGNED_BYTE);
		Finish.texUnit(shaderProgram, "tex0", 0);
		Texture Floor("LabTextures/floor.png", GL_TEXTURE_2D, GL_TEXTURE1, GL_RGBA, GL_UNSIGNED_BYTE);
		Floor.texUnit(shaderProgram, "tex1", 1);
		Texture Wall("LabTextures/wall.png", GL_TEXTURE_2D, GL_TEXTURE2, GL_RGBA, GL_UNSIGNED_BYTE);
		Wall.texUnit(shaderProgram, "tex2", 2);
		Texture Preview("LabTextures/back.png", GL_TEXTURE_2D, GL_TEXTURE3, GL_RGBA, GL_UNSIGNED_BYTE);
		Preview.texUnit(shaderProgram, "tex3", 3);
		Texture PlayButton("LabTextures/PlayButton.png", GL_TEXTURE_2D, GL_TEXTURE4, GL_RGBA, GL_UNSIGNED_BYTE);
		PlayButton.texUnit(shaderProgram, "tex4", 4);
		Texture ExitButton("LabTextures/ExitButton.png", GL_TEXTURE_2D, GL_TEXTURE5, GL_RGBA, GL_UNSIGNED_BYTE);
		ExitButton.texUnit(shaderProgram, "tex5", 5);
		Texture SettingsButton("LabTextures/SettingsButton.png", GL_TEXTURE_2D, GL_TEXTURE6, GL_RGBA, GL_UNSIGNED_BYTE);
		SettingsButton.texUnit(shaderProgram, "tex6", 6);
		Texture Resolution800x600Button("LabTextures/800x600Button.png", GL_TEXTURE_2D, GL_TEXTURE7, GL_RGBA, GL_UNSIGNED_BYTE);
		Resolution800x600Button.texUnit(shaderProgram, "tex7", 7);
		Texture Resolution1280x720Button("LabTextures/1280x720Button.png", GL_TEXTURE_2D, GL_TEXTURE8, GL_RGBA, GL_UNSIGNED_BYTE);
		Resolution1280x720Button.texUnit(shaderProgram, "tex8", 8);
		Texture Resolution1920x1080Button("LabTextures/1920x1080Button.png", GL_TEXTURE_2D, GL_TEXTURE9, GL_RGBA, GL_UNSIGNED_BYTE);
		Resolution1920x1080Button.texUnit(shaderProgram, "tex9", 9);

		glEnable(GL_DEPTH_TEST);

		glm::vec3 startCamPos = glm::vec3(24.0f, 0.0f, 24.0f);
		glm::vec3 startOrientation = glm::vec3(0.0f, 0.0f, -0.1f);
		glm::vec3 defaultCamPos = glm::vec3(0.0f, 0.0f, 2.0f);

		double lastTime = glfwGetTime();

		Camera camera(width, height, startCamPos);
		Camera MenuCamera(width, height, defaultCamPos);
		Camera SettingsCamera(width, height, defaultCamPos);
		Camera FinishCamera(width, height, defaultCamPos);

		GLenum error = glGetError();
		if (error != GL_NO_ERROR) {
			std::cout << "OpenGL error: " << error << std::endl;
		}
	
		bool isSettingsMode = false;
		//Main while loop
while (!glfwWindowShouldClose(window))	
{
	glClearColor(0.7f, 0.74f, 1.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	double currentTime;


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

		SettingsButton.Bind();
		SettingsButtonVAO.Bind();
		glDrawElements(GL_TRIANGLES, SizeSettingsButtonIndices / sizeof(int), GL_UNSIGNED_INT, 0);

		ExitButton.Bind();
		ExitButtonVAO.Bind();
		glDrawElements(GL_TRIANGLES, SizeExitButtonIndices / sizeof(int), GL_UNSIGNED_INT, 0);
		
		if (MenuCamera.ExitButtonClick(window))
		{
			glfwSetWindowShouldClose(window, GL_TRUE);
		}
		if (MenuCamera.SettingsButtonClick(window))
		{
				shaderProgram.Activate();
				SettingsCamera.Matrix(45.0f, 0.1f, 100.0f, shaderProgram, "camMatrix");

				Preview.Bind();
				SettingsMenuVAO.Bind();
				glDrawElements(GL_TRIANGLES, SizeSettingsMenuIndices / sizeof(int), GL_UNSIGNED_INT, 0);

				Resolution800x600Button.Bind();
				Resolution800x600ButtonVAO.Bind();
				glDrawElements(GL_TRIANGLES, SizeResolution800x600ButtonIndices / sizeof(int), GL_UNSIGNED_INT, 0);

				Resolution1280x720Button.Bind();
				Resolution1280x720ButtonVAO.Bind();
				glDrawElements(GL_TRIANGLES, SizeResolution1280x720ButtonIndices / sizeof(int), GL_UNSIGNED_INT, 0);

				Resolution1920x1080Button.Bind();
				Resolution1920x1080ButtonVAO.Bind();
				glDrawElements(GL_TRIANGLES, SizeResolution1920x1080ButtonIndices / sizeof(int), GL_UNSIGNED_INT, 0);

				if (SettingsCamera.Resolution800x600ButtonClick(window))
				{
					width = 800;
					height = 600;
					glfwSetWindowSize(window, width, height);
					glViewport(0, 0, width, height);
					camera.width = 800;
					camera.height = 600;
					MenuCamera.width = 800;
					MenuCamera.height = 600;
					SettingsCamera.width = 800;
					SettingsCamera.height = 600;
					FinishCamera.width = 800;
					FinishCamera.height = 600;
				};
				if (SettingsCamera.Resolution1280x720ButtonClick(window))
				{
					width = 1280;
					height = 720;
					glfwSetWindowSize(window, width, height);
					glViewport(0, 0, width, height);
					camera.width = 1280;
					camera.height = 720;
					MenuCamera.width = 1280;
					MenuCamera.height = 720;
					SettingsCamera.width = 1280;
					SettingsCamera.height = 720;
					FinishCamera.width = 1280;
					FinishCamera.height = 720;
				};
				if (SettingsCamera.Resolution1920x1080ButtonClick(window))
				{
					width = 1920;
					height = 1080;
					glfwSetWindowSize(window, width, height);
					glViewport(0, 0, width, height);
					camera.width = 1920;
					camera.height = 1080;
					MenuCamera.width = 1920;
					MenuCamera.height = 1080;
					SettingsCamera.width = 1920;
					SettingsCamera.height = 1080;
					FinishCamera.width = 1920;
					FinishCamera.height = 1080;
				};
				
		}
	}
	
	else // Если флаг установлен в false, отображаем игровой мир
	{
		double currentTime = glfwGetTime();
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
			MapFinishVAO.Bind();
			glDrawElements(GL_TRIANGLES, SizeMapFinishIndices / sizeof(int), GL_UNSIGNED_INT, 0);

			Floor.Bind();
			FloorVAO.Bind();
			glDrawElements(GL_TRIANGLES, SizeFloorIndices / sizeof(int), GL_UNSIGNED_INT, 0);

			Wall.Bind();
			WallVAO.Bind();
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
	SettingsButtonVAO.Delete();
	SettingsButtonVBO.Delete();
	SettingsButtonEBO.Delete();
	SettingsMenuVAO.Delete();
	SettingsMenuVBO.Delete();
	SettingsMenuEBO.Delete();
	MapFinishVAO.Delete();
	MapFinishVBO.Delete();
	MapFinishEBO.Delete();
	FloorVAO.Delete();
	FloorVBO.Delete();
	FloorEBO.Delete();
	WallVAO.Delete();
	WallVBO.Delete();
	WallEBO.Delete();
	Resolution800x600ButtonVAO.Delete();
	Resolution800x600ButtonVBO.Delete();
	Resolution800x600ButtonEBO.Delete();
	Resolution1280x720ButtonVAO.Delete();
	Resolution1280x720ButtonVBO.Delete();
	Resolution1280x720ButtonEBO.Delete();
	Resolution1920x1080ButtonVAO.Delete();
	Resolution1920x1080ButtonVBO.Delete();
	Resolution1920x1080ButtonEBO.Delete();
	shaderProgram.Delete();
	Finish.Delete();
	Floor.Delete();
	Wall.Delete();
	Preview.Delete();
	PlayButton.Delete();
	ExitButton.Delete();
	SettingsButton.Delete();
	Resolution800x600Button.Delete();
	Resolution1280x720Button.Delete();
	Resolution1920x1080Button.Delete();


	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;
}