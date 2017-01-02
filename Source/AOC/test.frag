#version 140

in vec4 Color;

out vec4 outColor;

void main() {
    //gl_FragColor = texture2D(0, vec(0.0, 0.0);
    //outColor = vec4(1.0, 0.0, 0.0, 0.5);
    outColor = Color;
}