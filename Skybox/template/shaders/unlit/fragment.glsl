#version 330 core

in vec3 o_positionWorld;
in vec3 o_normalWorld;
in vec2 o_uv0;
out vec4 FragColor;

uniform vec3 lightPos;
uniform vec3 lightColor;
uniform vec3 viewPos; 
uniform samplerCube skybox;


in vec3 N;
in vec3 P;



void main() {
    
    
	float ratio = 1.00 / 1.52;

    vec3 I = normalize(P - viewPos);
    vec3 R = reflect(I, normalize(N));
    FragColor = vec4(texture(skybox, R).rgb, 1.0);

}