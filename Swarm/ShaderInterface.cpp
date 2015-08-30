

#include "ShaderInterface.h"
#include <stdio.h>
#include <stdlib.h>

GLuint ShaderInterface::getProgramHandle()
{
    return shader->getProgramHandle();
}

GLint ShaderInterface::get_aPositionVertex()
{
    return _aPositionVertex;
}

GLint ShaderInterface::get_aPositionNormal()
{
	return _aPositionNormal;
}

GLint ShaderInterface::get_uColor()
{
    return _uColor;
}

GLint ShaderInterface::get_uLightPosition()
{
	return _uLightPosition;
}



ShaderInterface::ShaderInterface(std::string VS, std::string FS)
{
	std::string a = loadTextFromFile(VS);
	std::string b = loadTextFromFile(FS);

	const char * _vertexShaderString = a.c_str();
	const char * _fragmentShaderString =  b.c_str();
   
    shader = new ShaderLoader(_vertexShaderString, _fragmentShaderString);
     
    _aPositionVertex = glGetAttribLocation(shader->getProgramHandle(), "aPositionVertex");
	_aPositionNormal = glGetAttribLocation(shader->getProgramHandle(), "aPositionNormal");
    _uColor = glGetUniformLocation(shader->getProgramHandle(), "uColor");
	_uLightPosition = glGetUniformLocation(shader->getProgramHandle(), "uLightPostion");
 

}

ShaderInterface::~ShaderInterface()
{
    delete shader;
}

std::string ShaderInterface::loadTextFromFile(std::string shader_file)
{

	std::string shader_data;
	std::ifstream vertex_shader_file(shader_file.c_str(), std::ios::in);
	if (vertex_shader_file.is_open())
	{
		std::string line;
		while (std::getline(vertex_shader_file, line))
			shader_data += "\n" + line;

		shader_data += '\0';
		vertex_shader_file.close();
	}
	
	return shader_data;
}