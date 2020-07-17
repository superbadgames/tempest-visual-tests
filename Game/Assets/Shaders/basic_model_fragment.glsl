#version 430 core

in vec2 fs_texCoord;

uniform sampler2D tex;

out vec4 frag_color;

void main()
{
    frag_color = vec4(0.7f, 0.7f, 0.7f, 1.0f);
}
