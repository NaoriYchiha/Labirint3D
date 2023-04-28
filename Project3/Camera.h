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
public:
	glm::vec3 Position;
	glm::vec3 Orientation = glm::vec3(0.0f, 0.0f, -0.1f);
	glm::vec3 Up = glm::vec3(0.0f, 0.1f, 0.0f);

	bool firstClick = true;

	int width;
	int height;

	float speed = 0.03f;
	float sensivity = 100.0f;

	Camera(int width, int height, glm::vec3 position);
	void Matrix(float FOVdeg, float nearPlane, float farPlane, Shader& shader, const char* uniform);
	void Inputs(GLFWwindow* window);
	bool player_reached_finish();
	bool ButtonClick(GLFWwindow* window);
};

#endif