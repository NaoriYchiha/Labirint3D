#version 330 core

// Outputs colors in RGBA
out vec4 FragColor1;


// Inputs the color from the Vertex Shader
in vec3 color1;
// Inputs the texture coordinates from the Vertex Shader
in vec2 texCoord1;

// Gets the Texture Unit from the main function
uniform sampler2D texMenu0;


void main()
{
	vec4 MenuColor = texture(texMenu0, texCoord1);
	FragColor1 = MenuColor;
}