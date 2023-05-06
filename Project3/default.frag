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
uniform sampler2D tex7;
uniform sampler2D tex8;
uniform sampler2D tex9;
uniform sampler2D tex10;
uniform sampler2D tex11;
uniform sampler2D tex12;
uniform sampler2D tex13;
uniform sampler2D tex14;
uniform sampler2D tex15;
uniform sampler2D tex16;

void main()
{
   vec4 tex0Color = texture(tex0, texCoord);
   vec4 tex1Color = texture(tex1, texCoord);
   vec4 tex2Color = texture(tex2, texCoord);
   vec4 tex3Color = texture(tex3, texCoord);
   vec4 tex4Color = texture(tex4, texCoord); 
   vec4 tex5Color = texture(tex5, texCoord);
   vec4 tex6Color = texture(tex6, texCoord); 
   vec4 tex7Color = texture(tex7, texCoord); 
   vec4 tex8Color = texture(tex8, texCoord); 
   vec4 tex9Color = texture(tex9, texCoord);  
   vec4 tex10Color = texture(tex10, texCoord);
   vec4 tex11Color = texture(tex11, texCoord);
   vec4 tex12Color = texture(tex12, texCoord);  
   vec4 tex13Color = texture(tex13, texCoord); 
   vec4 tex14Color = texture(tex14, texCoord);  
   vec4 tex15Color = texture(tex15, texCoord);
   vec4 tex16Color = texture(tex16, texCoord);

   vec4 mixColor1 = mix(tex0Color, tex1Color, step(0, texCoord.y));
   vec4 mixColor2 = mix(mixColor1, tex2Color, step(0, texCoord.x));
   vec4 mixColor3 = mix(mixColor2, tex3Color, step(0, texCoord.y));
   vec4 mixColor4 = mix(mixColor3, tex4Color, step(0, texCoord.x));
   vec4 mixColor5 = mix(mixColor4, tex5Color, step(0, texCoord.y));
   vec4 mixColor6 = mix(mixColor5, tex6Color, step(0, texCoord.x));
   vec4 mixColor7 = mix(mixColor6, tex7Color, step(0, texCoord.y));
   vec4 mixColor8 = mix(mixColor7, tex8Color, step(0, texCoord.x));
   vec4 mixColor9 = mix(mixColor8, tex9Color, step(0, texCoord.y));
   vec4 mixColor10 = mix(mixColor9, tex10Color, step(0, texCoord.x));
   vec4 mixColor11 = mix(mixColor10, tex11Color, step(0, texCoord.y));
   vec4 mixColor12 = mix(mixColor11, tex12Color, step(0, texCoord.x)); 
   vec4 mixColor13 = mix(mixColor12, tex13Color, step(0, texCoord.y));
   vec4 mixColor14 = mix(mixColor13, tex14Color, step(0, texCoord.x));
   vec4 mixColor15 = mix(mixColor14, tex15Color, step(0, texCoord.y));
   vec4 mixColor16 = mix(mixColor15, tex16Color, step(0, texCoord.x));
   FragColor = mixColor16;
};