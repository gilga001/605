#version 330 core
layout (location = 0) in vec3 position; // 位置变量的属性为0

out vec4 vertexColor; // 为片段着色器指定一个颜色输出

void main()
{
    gl_Position = vec4(position, 1.0); // 把一个vec3作为vec4的构造器的参
    vertexColor = vec4(0.5f, 0.0f, 0.0f, 1.0f); // 把输出颜色设置为暗红
}
