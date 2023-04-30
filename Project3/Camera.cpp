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
	if (Position.y < 1.0f) Position.y = 1.0f;
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
	//granici wall 11
	if (Position.x > 2.9f && Position.x < 4.1f && Position.z > 19.0f && Position.z < 19.2f) { Position.z = 19.2f; }
	if (Position.x > 2.8f && Position.x < 2.9f && Position.z > 8.8f && Position.z < 19.2f) { Position.x = 2.8f; }
	if (Position.x > 4.1f && Position.x < 4.2f && Position.z > 8.8f && Position.z < 19.2f) { Position.x = 4.2f; }
	//granici wall 12
	if (Position.x > 0.9f && Position.x < 2.1f && Position.z > 15.8f && Position.z < 15.9f) { Position.z = 15.8f; }
	if (Position.x > 0.9f && Position.x < 2.1f && Position.z > 23.1f && Position.z < 23.2f) { Position.z = 23.2f; }
	if (Position.x > 0.8f && Position.x < 0.9f && Position.z > 16.0f && Position.z < 23.0f) { Position.x = 0.8f; }
	if (Position.x > 2.1f && Position.x < 2.2f && Position.z > 16.0f && Position.z < 23.0f) { Position.x = 2.2f; }
	//granici wall 13
	if (Position.x > -4.1f && Position.x < 1.1f && Position.z > 17.8f && Position.z < 17.9f) { Position.z = 17.8f; }
	if (Position.x > -4.1f && Position.x < 1.1f && Position.z > 19.0f && Position.z < 19.2f) { Position.z = 19.2f; }
	if (Position.x > -4.2f && Position.x < -4.1f && Position.z > 17.9f && Position.z < 19.1f) { Position.x = -4.2f; }
	//granici wall 14
	if (Position.x > -2.1f && Position.x < 0.1f && Position.z > 16.1f && Position.z < 16.2f) { Position.z = 16.2f; }
	if (Position.x > -2.2f && Position.x < -2.1f && Position.z > 8.9f && Position.z < 16.1f) { Position.x = -2.2f; }
	if (Position.x > 0.1f && Position.x < 0.2f && Position.z > 8.9f && Position.z < 16.1f) { Position.x = 0.2f; }
	//granici wall 15
	if (Position.x > -0.1f && Position.x < 2.1f && Position.z > 10.8f && Position.z < 10.9f) { Position.z = 10.8f; }
	if (Position.x > -0.1f && Position.x < 2.1f && Position.z > 12.1f && Position.z < 12.2f) { Position.z = 12.2f; }
	if (Position.x > 2.1f && Position.x < 2.2f && Position.z > 10.9f && Position.z < 12.1f) { Position.x = 2.2f; }
	//granici wall 16
	if (Position.x > -25.1f && Position.x < -14.9f && Position.z > 9.8f && Position.z < 9.9f) { Position.z = 9.8f; }
	if (Position.x > -25.1f && Position.x < -14.9f && Position.z > 11.1f && Position.z < 11.2f) { Position.z = 11.2f; }
	if (Position.x > -14.9f && Position.x < -14.8f && Position.z > 9.9f && Position.z < 11.1f) { Position.x = -14.8f; }
	//granici wall 17
	if (Position.x > -21.1f && Position.x < -19.9f && Position.z > 13.1f && Position.z < 13.2f) { Position.z = 13.2f; }
	if (Position.x > -21.2f && Position.x < -21.1f && Position.z > 10.9f && Position.z < 13.1f) { Position.x = -21.2f; }
	if (Position.x > -19.9f && Position.x < -19.8f && Position.z > 10.9f && Position.z < 13.1f) { Position.x = -19.8f; }
	//granici wall 18
	if (Position.x > -20.2f && Position.x < -20.1f && Position.z > 14.9f && Position.z < 25.1f) { Position.x = -20.2f; }
	if (Position.x > -18.9f && Position.x < -18.8f && Position.z > 14.9f && Position.z < 25.1f) { Position.x = -18.8f; }
	//granici wall 19
	if (Position.x > -24.2f && Position.x < -24.1f && Position.z > 13.9f && Position.z < 15.1f) { Position.x = -24.2f; }
	if (Position.x > -18.9f && Position.x < -18.8f && Position.z > 13.9f && Position.z < 15.1f) { Position.x = -18.8f; }
	if (Position.x > -24.1f && Position.x < -18.9f && Position.z > 13.8f && Position.z < 13.9f) { Position.z = 13.8f; }
	if (Position.x > -24.1f && Position.x < -18.9f && Position.z > 15.1f && Position.z < 15.2f) { Position.z = 15.2f; }
	//granici wall 20
	if (Position.x > -13.1f && Position.x < -11.9f && Position.z > 12.8f && Position.z < 12.9f) { Position.z = 12.8f; }
	if (Position.x > -13.2f && Position.x < -13.1f && Position.z > 12.9f && Position.z < 25.1f) { Position.x = -13.2f; }
	if (Position.x > -11.9f && Position.x < -11.8f && Position.z > 12.9f && Position.z < 25.1f) { Position.x = -11.8f; }
	//granici wall 21
	if (Position.x > -1.1f && Position.x < 0.1f && Position.z > 19.8f && Position.z < 19.9f) { Position.z = 19.8f; }
	if (Position.x > -1.2f && Position.x < -1.1f && Position.z > 19.9f && Position.z < 25.1f) { Position.x = -1.2f; }
	if (Position.x > 0.1f && Position.x < 0.2f && Position.z > 19.9f && Position.z < 25.1f) { Position.x = 0.2f; }
	//granici wall 22
	if (Position.x > -18.1f && Position.x < -4.9f && Position.z > 17.8f && Position.z < 17.9f) { Position.z = 17.8f; }
	if (Position.x > -18.1f && Position.x < -4.9f && Position.z > 19.1f && Position.z < 19.2f) { Position.z = 19.2f; }
	if (Position.x > -18.2f && Position.x < -18.1f && Position.z > 17.9f && Position.z < 19.1f) { Position.x = -18.2f; }
	if (Position.x > -4.9f && Position.x < -4.8f && Position.z > 17.9f && Position.z < 19.1f) { Position.x = -4.8f; }
	//granici wall 23
	if (Position.x > -13.1f && Position.x < -11.9f && Position.z > 12.1f && Position.z < 12.2f) { Position.z = 12.2f; }
	if (Position.x > -13.2f && Position.x < -13.1f && Position.z > 8.9f && Position.z < 12.1f) { Position.x = -13.2f; }
	if (Position.x > -11.9f && Position.x < -11.8f && Position.z > 8.9f && Position.z < 12.1f) { Position.x = -11.8f; }
	//granici wall 24
	if (Position.x > -20.1f && Position.x < -18.9f && Position.z > 3.8f && Position.z < 3.9f) { Position.z = 3.8f; }
	if (Position.x > -18.9f && Position.x < -18.8f && Position.z > 3.9f && Position.z < 8.1f) { Position.x = -18.8f; }
	if (Position.x > -20.2f && Position.x < -20.1f && Position.z > 3.9f && Position.z < 8.1f) { Position.x = -20.2f; }
	//granici wall 25
	if (Position.x > -25.1f && Position.x < -18.9f && Position.z > 2.1f && Position.z < 2.2f) { Position.z = 2.2f; }
	if (Position.x > -25.1f && Position.x < -18.9f && Position.z > 0.8f && Position.z < 0.9f) { Position.z = 0.8f; }
	if (Position.x > -18.9f && Position.x < -18.8f && Position.z > 0.9f && Position.z < 2.1f) { Position.x = -18.8f; }
	//granici wall 26
	if (Position.x > -20.1f && Position.x < -18.9f && Position.z > -3.2f && Position.z < -3.1f) { Position.z = -3.2f; }
	if (Position.x > -18.9f && Position.x < -18.8f && Position.z > -3.1f && Position.z < 1.1f) { Position.x = -18.8f; }
	if (Position.x > -20.2f && Position.x < -20.1f && Position.z > -3.1f && Position.z < 1.1f) { Position.x = -20.2f; }
	//granici wall 27
	if (Position.x > -18.1f && Position.x < -16.9f && Position.z > -0.2f && Position.z < -0.1f) { Position.z = -0.2f; }
	if (Position.x > -18.1f && Position.x < -16.9f && Position.z > 6.1f && Position.z < 6.2f) { Position.z = 6.2f; }
	if (Position.x > -16.9f && Position.x < -16.8f && Position.z > -0.1f && Position.z < 6.1f) { Position.x = -16.8f; }
	if (Position.x > -18.2f && Position.x < -18.1f && Position.z > -0.1f && Position.z < 6.1f) { Position.x = -18.2f; }
	//granici wall 28
	if (Position.x > -16.1f && Position.x < -14.9f && Position.z > 2.1f && Position.z < 2.2f) { Position.z = 2.2f; }
	if (Position.x > -14.9f && Position.x < -14.8f && Position.z > -5.1f && Position.z < 2.1f) { Position.x = -14.8f; }
	if (Position.x > -16.2f && Position.x < -16.1f && Position.z > -5.1f && Position.z < 2.1f) { Position.x = -16.2f; }
	//granici wall 29
	if (Position.x > -15.1f && Position.x < -9.9f && Position.z > -3.2f && Position.z < -3.1f) { Position.z = -3.2f; }
	if (Position.x > -15.1f && Position.x < -9.9f && Position.z > -1.9f && Position.z < -1.8f) { Position.z = -1.8f; }
	if (Position.x > -9.9f && Position.x < -9.8f && Position.z > -3.1f && Position.z < -1.9f) { Position.x = -9.8f; }
	//granici wall 30
	if (Position.x > -14.1f && Position.x < -12.9f && Position.z > -0.2f && Position.z < -0.1f) { Position.z = -0.2f; }
	if (Position.x > -14.1f && Position.x < -12.9f && Position.z > 3.1f && Position.z < 3.2f) { Position.z = 3.2f; }
	if (Position.x > -12.9f && Position.x < -12.8f && Position.z > -0.1f && Position.z < 3.1f) { Position.x = -12.8f; }
	if (Position.x > -14.2f && Position.x < -14.1f && Position.z > -0.1f && Position.z < 3.1f) { Position.x = -14.2f; }
	//granici wall 31
	if (Position.x > -12.1f && Position.x < -10.9f && Position.z > 1.8f && Position.z < 1.9f) { Position.z = 1.8f; }
	if (Position.x > -12.2f && Position.x < -12.1f && Position.z > 1.9f && Position.z < 9.1f) { Position.x = -12.2f; }
	if (Position.x > -10.9f && Position.x < -10.8f && Position.z > 1.9f && Position.z < 9.1f) { Position.x = -10.8f; }
	//granici wall 32
	if (Position.x > -16.1f && Position.x < -4.9f && Position.z > 5.8f && Position.z < 5.9f) { Position.z = 5.8f; }
	if (Position.x > -16.1f && Position.x < -4.9f && Position.z > 7.1f && Position.z < 7.2f) { Position.z = 7.2f; }
	if (Position.x > -4.9f && Position.x < -4.8f && Position.z > 5.9f && Position.z < 7.1f) { Position.x = -4.8f; }
	if (Position.x > -16.2f && Position.x < -16.1f && Position.z > 5.9f && Position.z < 7.1f) { Position.x = -16.2f; }
	//granici wall 33
	if (Position.x > -8.1f && Position.x < -5.9f && Position.z > 1.1f && Position.z < 1.2f) { Position.z = 1.2f; }
	if (Position.x > -5.9f && Position.x < -5.8f && Position.z > -5.1f && Position.z < 1.1f) { Position.x = -5.8f; }
	if (Position.x > -8.2f && Position.x < -8.1f && Position.z > -5.1f && Position.z < 1.1f) { Position.x = -8.2f; }
	//granici wall 34
	if (Position.x > -5.2f && Position.x < -5.1f && Position.z > -5.1f && Position.z < 2.1f) { Position.x = -5.2f; }
	if (Position.x > -3.9f && Position.x < -3.8f && Position.z > -5.1f && Position.z < 2.1f) { Position.x = -3.8f; }
	//granici wall 35
	if (Position.x > -8.1f && Position.x < -3.9f && Position.z > 1.8f && Position.z < 1.9f) { Position.z = 1.8f; }
	if (Position.x > -8.1f && Position.x < -3.9f && Position.z > 3.1f && Position.z < 3.2f) { Position.z = 3.2f; }
	if (Position.x > -3.9f && Position.x < -3.8f && Position.z > 1.9f && Position.z < 3.1f) { Position.x = -3.8f; }
	if (Position.x > -8.2f && Position.x < -8.1f && Position.z > 1.9f && Position.z < 3.1f) { Position.x = -8.2f; }
	//granici wall 36
	if (Position.x > -2.1f && Position.x < -0.9f && Position.z > -0.2f && Position.z < -0.1f) { Position.z = -0.2f; }
	if (Position.x > -2.2f && Position.x < -2.1f && Position.z > -0.1f && Position.z < 8.1f) { Position.x = -2.2f; }
	if (Position.x > -0.9f && Position.x < -0.8f && Position.z > -0.1f && Position.z < 8.1f) { Position.x = -0.8f; }
	//granici wall 37
	if (Position.x > 4.9f && Position.x < 6.1f && Position.z > 1.1f && Position.z < 1.2f) { Position.z = 1.2f; }
	if (Position.x > 6.1f && Position.x < 6.2f && Position.z > -5.1f && Position.z < 1.1f) { Position.x = 6.2f; }
	if (Position.x > 4.8f && Position.x < 4.9f && Position.z > -5.1f && Position.z < 1.1f) { Position.x = 4.8f; }
	//granici wall 38
	if (Position.x > 4.9f && Position.x < 6.1f && Position.z > 2.8f && Position.z < 2.9f) { Position.z = 2.8f; }
	if (Position.x > 6.1f && Position.x < 6.2f && Position.z > 2.9f && Position.z < 8.1f) { Position.x = 6.2f; }
	if (Position.x > 4.8f && Position.x < 4.9f && Position.z > 2.9f && Position.z < 8.1f) { Position.x = 4.8f; }
	//granici wall 39
	if (Position.x > -0.1f && Position.x < 6.1f && Position.z > 1.8f && Position.z < 1.9f) { Position.z = 1.8f; }
	if (Position.x > -0.1f && Position.x < 6.1f && Position.z > 3.1f && Position.z < 3.2f) { Position.z = 3.2f; }
	if (Position.x > 6.1f && Position.x < 6.2f && Position.z > 1.9f && Position.z < 3.1f) { Position.x = 6.2f; }
	if (Position.x > -0.2f && Position.x < -0.1f && Position.z > 1.9f && Position.z < 3.1f) { Position.x = -0.2f; }
	//granici wall 40
	if (Position.x > 6.9f && Position.x < 8.1f && Position.z > -2.2f && Position.z < -2.1f) { Position.z = -2.2f; }
	if (Position.x > 6.9f && Position.x < 8.1f && Position.z > 6.1f && Position.z < 6.2f) { Position.z = 6.2f; }
	if (Position.x > 6.8f && Position.x < 6.9f && Position.z > -2.1f && Position.z < 6.1f) { Position.x = 6.8f; }
	if (Position.x > 8.1f && Position.x < 8.2f && Position.z > -2.1f && Position.z < 6.1f) { Position.x = 8.2f; }
	//granici wall 41
	if (Position.x > 7.9f && Position.x < 17.1f && Position.z > 0.8f && Position.z < 0.9f) { Position.z = 0.8f; }
	if (Position.x > 7.9f && Position.x < 17.1f && Position.z > 2.1f && Position.z < 2.2f) { Position.z = 2.2f; }
	if (Position.x > 17.1f && Position.x < 17.2f && Position.z > 0.9f && Position.z < 2.1f) { Position.x = 17.2f; }
	//granici wall 42
	if (Position.x > 15.8f && Position.x < 15.9f && Position.z > -5.1f && Position.z < 1.1f) { Position.x = 15.8f; }
	if (Position.x > 17.1f && Position.x < 17.2f && Position.z > -5.1f && Position.z < 1.1f) { Position.x = 17.2f; }
	//granici wall 43
	if (Position.x > 15.9f && Position.x < 17.1f && Position.z > 2.8f && Position.z < 2.9f) { Position.z = 2.8f; }
	if (Position.x > 15.8f && Position.x < 15.9f && Position.z > 2.9f && Position.z < 8.1f) { Position.x = 15.8f; }
	if (Position.x > 17.1f && Position.x < 17.2f && Position.z > 2.9f && Position.z < 8.1f) { Position.x = 17.2f; }
	//granici wall 44
	if (Position.x > 18.9f && Position.x < 25.1f && Position.z > 0.8f && Position.z < 0.9f) { Position.z = 0.8f; }
	if (Position.x > 18.9f && Position.x < 25.1f && Position.z > 2.1f && Position.z < 2.2f) { Position.z = 2.2f; }
	//granici wall 45
	if (Position.x > 17.9f && Position.x < 19.1f && Position.z > -2.2f && Position.z < -2.1f) { Position.z = -2.2f; }
	if (Position.x > 17.9f && Position.x < 19.1f && Position.z > 6.1f && Position.z < 6.2f) { Position.z = 6.2f; }
	if (Position.x > 17.8f && Position.x < 17.9f && Position.z > -2.1f && Position.z < 6.1f) { Position.x = 17.8f; }
	if (Position.x > 19.1f && Position.x < 19.2f && Position.z > -2.1f && Position.z < 6.1f) { Position.x = 19.2f; }
	//granici wall 46
	if (Position.x > 21.9f && Position.x < 23.6f && Position.z > 2.8f && Position.z < 2.9f) { Position.z = 2.8f; }
	if (Position.x > 21.8f && Position.x < 21.9f && Position.z > 2.9f && Position.z < 8.1f) { Position.x = 21.8f; }
	if (Position.x > 23.6f && Position.x < 23.7f && Position.z > 2.9f && Position.z < 8.1f) { Position.x = 23.7f; }

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

bool Camera::Resolution800x600ButtonClick(GLFWwindow* window) {


	glfwGetCursorPos(window, &xPos, &yPos);
	bool isMouseButtonPressed = glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS;

	if (isMouseButtonPressed && !m_isSettingsMenuVisible && xPos >= width * 0.01f && xPos <= width * 0.165f && yPos >= height * 0.05f && yPos <= height * 0.145f)
	{
		return true;
	}
	else
		return false;
}

bool Camera::Resolution1280x720ButtonClick(GLFWwindow* window){

	glfwGetCursorPos(window, &xPos, &yPos);
	bool isMouseButtonPressed = glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS;

	if (isMouseButtonPressed && !m_isSettingsMenuVisible && xPos >= width * 0.175f && xPos <= width * 0.33f && yPos >= height * 0.05f && yPos <= height * 0.145f)
	{
		return true;
	}
	else
		return false;
}

bool Camera::Resolution1920x1080ButtonClick(GLFWwindow* window) {

	glfwGetCursorPos(window, &xPos, &yPos);
	bool isMouseButtonPressed = glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS;

	if (isMouseButtonPressed && !m_isSettingsMenuVisible && xPos >= width * 0.34f && xPos <= width * 0.495f && yPos >= height * 0.05f && yPos <= height * 0.145f)
	{
		return true;
	}
	else
		return false;
}

bool Camera::player_reached_finish() {
	if (Position.x >= 23.6f && Position.x <= 25.1f && Position.y >= 0.51f && Position.y <= 2.51f && Position.z >= 7.5f && Position.z <= 8.1f) {
		return true;
	}
	else
		return false;
}



bool Camera::PlayButtonClick(GLFWwindow* window) {

	glfwGetCursorPos(window, &xPos, &yPos);

	bool isMouseButtonPressed = glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS;
	
	if (isMouseButtonPressed && !m_wasMouseButtonPressed && m_isMenuVisible && !m_isSettingsMenuVisible && xPos >= width * 0.4088f && xPos <= width * 0.56f && yPos >= height * 0.435f && yPos <= height * 0.514f)
	{
		 m_isMenuVisible = !m_isMenuVisible;
	}
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
	{
		m_isMenuVisible = !m_isMenuVisible;
	}
	m_wasMouseButtonPressed = isMouseButtonPressed;

	return m_isMenuVisible;
}

bool Camera::SettingsButtonClick(GLFWwindow* window) {

	glfwGetCursorPos(window, &xPos, &yPos);
	bool isMouseButtonPressed = glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS;
	
	if (isMouseButtonPressed && !m_wasSettingsMouseButtonPressed && !m_isSettingsMenuVisible && xPos >= width * 0.4088f && xPos <= width * 0.56f && yPos >= height * 0.593f && yPos <= height * 0.671f)
	{
		m_isSettingsMenuVisible = !m_isSettingsMenuVisible;
	}
	if (glfwGetKey(window, GLFW_KEY_BACKSPACE) == GLFW_PRESS && m_isSettingsMenuVisible)
	{
		m_isSettingsMenuVisible = !m_isSettingsMenuVisible;
	}
	m_wasMouseButtonPressed = isMouseButtonPressed;

	return m_isSettingsMenuVisible;
}

bool Camera::ExitButtonClick(GLFWwindow* window) {

	glfwGetCursorPos(window, &xPos, &yPos);
	bool isMouseButtonPressed = glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS;
	
	if (isMouseButtonPressed && m_isMenuVisible && !m_isSettingsMenuVisible && xPos >= width * 0.4088f && xPos <= width * 0.56f && yPos >= height * 0.756f && yPos <= height * 0.841f)
	{
		return true;
	}
	else
		return false;
}

