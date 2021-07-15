#version 330 core

uniform vec2 resolution;
uniform vec2 camera;
uniform vec2 pos;
uniform float height;

#define WIDTH 5.0

out vec2 uv;

vec2 project_point(vec2 point)
{
    return 2.0 * (point - camera) / resolution;
}

void main() {
    uv = vec2(float(gl_VertexID & 1), float((gl_VertexID >> 1) & 1));
    gl_Position = vec4(
        project_point(uv * vec2(WIDTH, height) + pos),
        0.0,
        1.0);
}