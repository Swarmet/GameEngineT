#version 330
attribute vec3 aPostionVertex;

void main()
{

	gl_Position = gl_ModleViewProjectionMatrix * vec4(aPostionVertex, 1)

}