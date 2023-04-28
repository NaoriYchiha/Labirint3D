#version 330 core
out vec4 FragColor;

in vec3 color;
in vec2 texCoord;

uniform sampler2D tex0;
uniform sampler2D tex1;
uniform sampler2D tex2;
uniform sampler2D tex3;
uniform sampler2D tex4;
uniform sampler2D tex5;
uniform sampler2D tex6;

void main()
{
   vec4 tex0Color = texture(tex0, texCoord);
   vec4 tex1Color = texture(tex1, texCoord);
   vec4 tex2Color = texture(tex2, texCoord);
   vec4 tex3Color = texture(tex3, texCoord);
   vec4 tex4Color = texture(tex4, texCoord); 
   vec4 tex5Color = texture(tex5, texCoord);
   vec4 tex6Color = texture(tex6, texCoord);

   vec4 mixColor1 = mix(tex0Color, tex1Color, step(0, texCoord.y));
   vec4 mixColor2 = mix(mixColor1, tex2Color, step(0, texCoord.x));
   vec4 mixColor3 = mix(mixColor2, tex3Color, step(0, texCoord.y));
   vec4 mixColor4 = mix(mixColor3, tex4Color, step(0, texCoord.x));
   vec4 mixColor5 = mix(mixColor4, tex5Color, step(0, texCoord.y));
   vec4 mixColor6 = mix(mixColor5, tex6Color, step(0, texCoord.x));
   FragColor = mixColor6;
};