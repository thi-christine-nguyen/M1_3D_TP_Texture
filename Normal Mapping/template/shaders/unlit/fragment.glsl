#version 330 core

in vec3 o_positionWorld;
in vec3 o_normalWorld;
in vec2 o_uv0;
out vec4 FragColor;

uniform vec4 color;
uniform sampler2D colorTexture;
uniform sampler2D normaleTexture; 


uniform vec3 lightPos;
uniform vec3 lightColor;
uniform vec3 viewPos; 

in mat3 TBN; 



void main() {

    vec3 normal = texture(normaleTexture, o_uv0).rgb; 
    normal = normal * 2.0 - 1.0; 
   
    // ambient
    float ambientStrength = 0.5;
    vec3 ambient = ambientStrength * lightColor ;
    // diffuse
    vec3 norm = normalize ( TBN * normal ) ;
    vec3 lightDir = normalize ( lightPos - o_positionWorld ) ;
    float diff = max ( dot ( norm , lightDir ) , 0.0) ;
    vec3 diffuse = diff * lightColor ;
    // specular
    float specularStrength = 0.5;
    vec3 viewDir = normalize ( viewPos - o_positionWorld ) ;
    vec3 reflectDir = reflect ( - lightDir , norm ) ;
    float spec = pow ( max ( dot ( viewDir , reflectDir ) , 0.0) , 32) ;
    vec3 specular = specularStrength * spec * lightColor ;
    vec3 result = ( ambient + diffuse + specular ) ;
    FragColor = vec4 ( result , 1.0) ;


    FragColor *= texture(colorTexture, o_uv0); 
   
}