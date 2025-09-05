#version 450

layout (location = 0) in vec4 position;
layout (location = 1) in vec4 color;
layout (location = 2) in mat4 model;

out vec4 i_color;

uniform mat4 projection;
uniform mat4 view;

void main(void){
    gl_Position = projection * view * model * position;
    i_color = color;
}