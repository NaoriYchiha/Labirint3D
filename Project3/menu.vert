#version 330 core

// Positions/Coordinates
layout (location = 0) in vec3 aPos1;
// Colors
layout (location = 1) in vec3 aColor1;
// Texture Coordinates
layout (location = 2) in vec2 aTex1;


// Outputs the color for the Fragment Shader
out vec3 color1;
// Outputs the texture coordinates to the fragment shader
out vec2 texCoord1;



uniform mat4 camMenu;

void main()
{
	// Outputs the positions/coordinates of all vertices
	gl_Position = camMenu * vec4(aPos1, 1.0);
	// Assigns the colors from the Vertex Data to "color"
	color1 = aColor1;
	// Assigns the texture coordinates from the Vertex Data to "texCoord"
	texCoord1 = aTex1;
}