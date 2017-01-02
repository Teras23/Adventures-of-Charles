#version 140

in vec2 vertexPosition;
in vec4 inColor;

out vec4 Color;

void main() {
    Color = inColor;
    gl_Position.xy = vertexPosition;
    gl_Position.z = 0.0;
    gl_Position.w = 1.0;
}