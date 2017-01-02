#version 140

in vec2 inVertexPosition;
in vec4 inColor;
in vec2 inTextureCoord;

out vec4 Color;
out vec2 TextureCoord;

uniform mat4 projectionMatrix;
uniform mat4 modelMatrix;

void main() {
    Color = inColor;
    TextureCoord = inTextureCoord;
    gl_Position = projectionMatrix * modelMatrix * vec4(inVertexPosition, 1.0, 1.0);
    //gl_Position = vec4(inVertexPosition, 1.0, 1.0);
}