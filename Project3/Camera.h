#ifndef CAMERA_CLASS_H
#define CAMERA_CLASS_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/rotate_vector.hpp>
#include <glm/gtx/vector_angle.hpp>

#include "ShaderClass.h"

class Camera
{
private:
	bool m_wasMouseButtonPressed = false;
	bool m_isMenuVisible = true;
	bool m_wasSettingsMouseButtonPressed = false;
	bool m_isSettingsMenuVisible = false;

public:


	glm::vec3 Position;
	glm::vec3 Orientation = glm::vec3(0.0f, 0.0f, -0.1f);
	glm::vec3 Up = glm::vec3(0.0f, 0.1f, 0.0f);

	bool firstClick = true;

	int width;
	int height;

	double xPos;
	double yPos;

	float speed = 0.03f;
	float sensivity = 100.0f;

	Camera(int width, int height, glm::vec3 position);
	void Matrix(float FOVdeg, float nearPlane, float farPlane, Shader& shader, const char* uniform);
	void Inputs(GLFWwindow* window);
	bool player_reached_finish();
	bool PlayButtonClick(GLFWwindow* window);
	bool SettingsButtonClick(GLFWwindow* window);
	bool ExitButtonClick(GLFWwindow* window);
	bool Resolution800x600ButtonClick(GLFWwindow* window);
	bool Resolution1280x720ButtonClick(GLFWwindow* window);
	bool Resolution1920x1080ButtonClick(GLFWwindow* window);
};

#endif