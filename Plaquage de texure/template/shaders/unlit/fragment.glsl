#version 330 core

in vec3 o_positionWorld;
in vec3 o_normalWorld;
in vec2 o_uv0;
out vec4 FragColor;

uniform vec4 color;
uniform sampler2D colorTexture;

void main() {
    //FragColor = color;
    FragColor = texture(colorTexture, o_uv0) * color;
    // DEBUG: position
    // FragColor = vec4(o_positionWorld, 1.0);
    // DEBUG: normal
    // FragColor = vec4(0.5 * o_normalWorld + vec3(0.5) , 1.0);
    // DEBUG: uv0
    // FragColor = vec4(o_uv0, 1.0);
}