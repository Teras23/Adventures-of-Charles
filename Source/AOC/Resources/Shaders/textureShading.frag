#version 140

in vec4 Color;
in vec2 TextureCoord;

out vec4 outColor;

uniform sampler2D tex;

void main() {
    //outColor = Color;
    outColor = texture(tex, TextureCoord) * Color;
}