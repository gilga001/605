#version 330 core
out vec4 color;

uniform vec4 ourColor; //在程序代码中设置

void main()
{
    color = ourColor;
}  
