#version 450

in vec4 position;
in vec4 color;

in mat4 model;

out vec4 i_color;

uniform mat4 projection;
uniform mat4 view;

void main(void){
    gl_Position = projection * view * model * position;
    i_color = color;
}