#include "Camera.h"

Camera::Camera(int width, int height, glm::vec3 position) {
	Camera::width = width;
	Camera::height = height;
	Position = position;
}

void Camera::Matrix(float FOVdeg, float nearPlane, float farPlane, Shader& shader, const char* uniform) {
	glm::mat4 view = glm::mat4(1.0f);
	glm::mat4 projection = glm::mat4(1.0f);

	view = glm::lookAt(Position, Position + Orientation, Up);
	projection = glm::perspective(glm::radians(FOVdeg), (float)(width / height), nearPlane, farPlane);

	glUniformMatrix4fv(glGetUniformLocation(shader.ID, uniform), 1, GL_FALSE, glm::value_ptr(projection * view));
}

void Camera::Inputs(GLFWwindow* window) {
	
	float jumpSpeed = 0.03f;
	//granici polya
	if (Position.x < -24.8f) Position.x = -24.8f;
	if (Position.x > 24.9f) Position.x = 24.9f;
	if (Position.z < -4.8f) Position.z = -4.8f;
	if (Position.z > 24.9f) Position.z = 24.9f;
	if (Position.y < 1.0f ) Position.y = 1.0f;
	//granici wall 1
	if (Position.x > -20.2f && Position.x < 25.0f && Position.z > 7.8f && Position.z < 8.0f) { Position.z = 7.8f; }
	if (Position.x > -20.2f && Position.x < 25.0f && Position.z > 9.0f && Position.z < 9.2f) { Position.z = 9.2f; }
	if (Position.x > -20.2f && Position.x < 25.0f && Position.z > 8.0f && Position.z < 9.0f) { Position.x = -20.2f; }
	//granici wall 2
	if (Position.x > 19.8f && Position.x < 25.0f && Position.z > 10.85f && Position.z < 11.0f) { Position.z = 10.85f; }
	if (Position.x > 19.8f && Position.x < 25.0f && Position.z > 11.9f && Position.z < 12.15f) { Position.z = 12.15f; }
	if (Position.x > 19.8f && Position.x < 25.0f && Position.z > 11.0f && Position.z < 11.9f) { Position.x = 19.8f; }
	//granici wall 3
	if (Position.x > 19.9f && Position.x < 21.1f && Position.z > 16.8f && Position.z < 17.0f) { Position.z = 16.8f; }
	if (Position.x > 19.8f && Position.x < 19.9f && Position.z > 17.0f && Position.z < 25.0f) { Position.x = 19.8f; }
	if (Position.x > 21.1f && Position.x < 21.2f && Position.z > 17.0f && Position.z < 25.0f) { Position.x = 21.2f; }
	//granici wall 4
	if (Position.x > 13.0f && Position.x < 20.0f && Position.z > 19.8f && Position.z < 19.9f) { Position.z = 19.8f; }
	if (Position.x > 13.0f && Position.x < 20.0f && Position.z > 21.0f && Position.z < 21.2f) { Position.z = 21.2f; }
	if (Position.x > 12.8f && Position.x < 13.0f && Position.z > 20.0f && Position.z < 21.0f) { Position.x = 12.8f; }
	//granici wall 5
	if (Position.x > 7.9f && Position.x < 9.1f && Position.z > 15.0f && Position.z < 15.2f) { Position.z = 15.2f; }
	if (Position.x > 7.8f && Position.x < 7.9f && Position.z > 9.0f && Position.z < 15.0f) { Position.x = 7.8f; }
	if (Position.x > 9.1f && Position.x < 9.2f && Position.z > 9.0f && Position.z < 15.0f) { Position.x = 9.2f; }
	//granici wall 6
	if (Position.x > 4.9f && Position.x < 13.1f && Position.z > 13.1f && Position.z < 13.2f) { Position.z = 13.2f; }
	if (Position.x > 4.9f && Position.x < 13.1f && Position.z > 11.8f && Position.z < 11.9f) { Position.z = 11.8f; }
	if (Position.x > 4.8f && Position.x < 4.9f && Position.z > 11.9f && Position.z < 13.1f) { Position.x = 4.8f; }
	if (Position.x > 13.1f && Position.x < 13.2f && Position.z > 11.9f && Position.z < 13.1f) { Position.x = 13.2f; }
	//granici wall 7
	if (Position.x > 7.8f && Position.x < 9.2f && Position.z > 15.8f && Position.z < 15.9f) { Position.z = 15.8f; }
	if (Position.x > 7.8f && Position.x < 7.9f && Position.z > 15.9f && Position.z < 25.0f) { Position.x = 7.8f; }
	if (Position.x > 9.1f && Position.x < 9.2f && Position.z > 15.9f && Position.z < 25.0f) { Position.x = 9.2f; }
	//granici wall 8
	if (Position.x > 9.8f && Position.x < 11.2f && Position.z > 13.8f && Position.z < 13.9f) { Position.z = 13.8f; }
	if (Position.x > 9.8f && Position.x < 11.2f && Position.z > 19.1f && Position.z < 19.2f) { Position.z = 19.2f; }
	if (Position.x > 9.8f && Position.x < 9.9f && Position.z > 14.0f && Position.z < 19.0f) { Position.x = 9.8f; }
	if (Position.x > 11.1f && Position.x < 11.2f && Position.z > 14.0f && Position.z < 19.0f) { Position.x = 11.2f; }
	//granici wall 9
	if (Position.x > 11.0f && Position.x < 20.0f && Position.z > 14.8f && Position.z < 15.0f) { Position.z = 14.8f; }
	if (Position.x > 11.0f && Position.x < 20.0f && Position.z > 16.0f && Position.z < 16.2f) { Position.z = 16.2f; }
	if (Position.x > 20.0f && Position.x < 20.2f && Position.z > 15.0f && Position.z < 16.0f) { Position.x = 20.2f; }
	//granici wall 10
	if (Position.x > 17.9f && Position.x < 19.1f && Position.z > 12.8f && Position.z < 12.9f) { Position.z = 12.8f; }
	if (Position.x > 17.8f && Position.x < 17.9f && Position.z > 12.9f && Position.z < 15.1f) { Position.x = 17.8f; }
	if (Position.x > 19.1f && Position.x < 19.2f && Position.z > 12.9f && Position.z < 15.1f) { Position.x = 19.2f; }


	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
	{
		Position += speed * Orientation;
		if (Position.y > 1.5f) Position -= jumpSpeed * 2.0f * Up;
	}
	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
	{
		Position += speed * 0.05f * -glm::normalize(glm::cross(Orientation, Up));
		if (Position.y > 1.5f) Position -= jumpSpeed * 2.0f * Up;
	}
	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
	{
		Position += speed * -Orientation;
		if (Position.y > 1.5f) Position -= jumpSpeed * 2.0f * Up;
	}
	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
	{
		Position += speed * 0.05f * glm::normalize(glm::cross(Orientation, Up));
		if (Position.y > 1.5f) Position -= jumpSpeed * 2.0f * Up;
	}
	if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS)
	{
		Position += jumpSpeed * Up;
		if (Position.y > 1.5f) Position -= jumpSpeed * 2.0f * Up;
	}	
	if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_RELEASE)
	{
		Position -= jumpSpeed * Up * Up * 2.0f;
	}
	if (glfwGetKey(window, GLFW_KEY_LEFT_CONTROL) == GLFW_PRESS)
	{
		Position += speed * -Up;
	}
	if (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS)
	{
		speed = 0.04f;
	}
	if (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_RELEASE)
	{
		speed = 0.02f;
	}
	if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS)
	{
		glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_HIDDEN);

		if (firstClick)
		{
			glfwSetCursorPos(window, (width / 2), (height / 2));
			firstClick = false;
		}

		double mouseX;
		double mouseY;
		glfwGetCursorPos(window, &mouseX, &mouseY);

		float rotX = sensivity * (float)(mouseY - (height / 2)) / height;
		float rotY = sensivity * (float)(mouseX - (width / 2)) / width;

		glm::vec3 newOrientation = glm::rotate(Orientation, glm::radians(-rotX), glm::normalize(glm::cross(Orientation, Up)));

		if (!(glm::angle(newOrientation, Up) <= glm::radians(5.0f) or glm::angle(newOrientation, -Up) <= glm::radians(5.0f))) 
		{
			Orientation = newOrientation;
		}
		Orientation = glm::rotate(Orientation, glm::radians(-rotY), Up);

		glfwSetCursorPos(window, (width / 2), (height / 2));
	}
	
	else if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_RELEASE)
	{
		glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
		firstClick = true;
	}
	
}
